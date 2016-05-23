#! /usr/bin/env bash

BW='\x1b[37;1m'  # bold white
BR='\x1b[31;1m'  # bold red
BG='\x1b[32;1m'  # bold red
NC='\x1b[37;0m'  # no color

HELP="Usage: ./full_test.sh
Options:
  -c   run only dependency checking
  -t   run only tests
  -s   run only stylechecks
  -d   run only docscheck
  -h   print this help
Example:
 ./run_tests.sh -sd"

function error { >&2 echo -e "${BR}$1${NC}"; }
function showinfo { echo -e "${BW}$1${NC}"; }
function ok { echo -e "${BG}$1${NC}"; }

# check the path is correct
cwd=${PWD##*/}
if [ "$cwd" != "Grafi" ]; then
    error "Run from Grafi/ directory in this project!"
    exit 1
fi

# A POSIX variable
OPTIND=1         # Reset in case getopts has been used previously in the shell.

# Initialize our own variables:
RUNTESTS=false
STYLECHECK=false
DOCSCHECK=false
CHECKDEPS=false

while getopts "htdcs" opt; do
    case "$opt" in
    h|\?)
        echo "$HELP";
        exit 0
        ;;
    t)  RUNTESTS=true;
        ;;
    s)  STYLECHECK=true;
        ;;
    d)  DOCSCHECK=true;
        ;;
    c)  CHECKDEPS=true;
        ;;
    esac
done

# If all false, run everything
if [ "$RUNTESTS" = "false" ] && [ "$STYLECHECK" == "false" ] && [ "$DOCSCHECK" == "false" ] &&
   [ "$CHECKDEPS" == "false" ]; then
    RUNTESTS=true
    STYLECHECK=true
    DOCSCHECK=true
    CHECKDEPS=true
fi


NUMBER_OF_JOBS=$(cat /proc/cpuinfo | grep processor | wc -l)
NUMBER_OF_JOBS=$(($NUMBER_OF_JOBS+1))

if [ "$CHECKDEPS" = "true" ]; then
    showinfo "Configuring ..."
    ./scripts/configure.sh
    if [ $? -ne 0 ]; then
        error "Error: prerequisites are not satisfied"
        exit 1
    fi
fi

# TESTS
if [ "$RUNTESTS" = "true" ]; then
    showinfo "Looking for tests ..."
    for filename in $(find -regex 'src/.*\.cpp')
    do
        testname="$(dirname $filename)/$(basename $filename .cpp)_test.cpp"
        testname="./test/${testname#*/}"
        if [ ! -f $testname ]; then
            echo -e "${BR}Filename: ${NC}$filename${BR} does not have a test!"
            echo -e "Make sure file ${NC}$testname${BR} exists!${NC}"
            exit 2
        fi
    done
    ok "All cpp files have tests."

    showinfo "Compiling tests ..."
    mkdir -p build
    cd build
    cmake ..
    make -j8 tests
    if [ $? -ne 0 ]; then
        error "Error: there are compile errors!"
        exit 3
    fi
    cd -

    showinfo "Running tests ..."
    ./bin/tests
    if [ $? -ne 0 ]; then
        error "Error: there are failed tests!"
        exit 4
    fi
    ok "All tests compile and pass."
fi

# STYLE
if [ "$STYLECHECK" = "true" ]; then
    showinfo "Checking code style ..."

    STYLEFILTERS="-legal,-runtime/reference,-readability/streams"
    find -regex '\./\(src\|test\)\/.*\.\(cpp\|hpp\)' | xargs -n 1  -P 8 \
        python2 scripts/cpplint.py "--filter=$STYLEFILTERS" "--linelength=100" \
                                   "--extensions=cpp,hpp"
    ERRORCODE=$?;
    if [ $ERRORCODE -ne 0 ]; then
        error "Error: there were sytle mistakes!"
        echo "(If you feel errors are unjust, edit this file and add exceptions (ln. 103).)"
        exit 5
    fi
    ok "Code style check passed."
fi

if [ "$DOCSCHECK" = "true" ]; then
    showinfo "Checking docs ..."

    dir=`mktemp -d`
    cd build; make docs > /dev/null 2> "$dir/out"; cd -;
    if [ -s "$dir/out" ]; then
        cat "$dir/out"
        error "Error: there are documentation warnings!"
        echo "(If you feel they are unjust, edit this file and add exceptions (ln. 130).)"
        exit 6
    fi
    ok "No undocumented features found."
fi

ok "All done, feel free to commit."
