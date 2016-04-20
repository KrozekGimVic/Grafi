#!/bin/bash

# this script checks system' configuration

BW='\x1b[37;1m'  # bold white
BR='\x1b[31;1m'  # bold red
BG='\x1b[32;1m'  # bold red
NC='\x1b[37;0m'  # no color

# packages and commands -- default = ubuntu

CHECK_PACKAGE="dpkg -s"
INSTALL_PACKAGE="sudo apt-get install"

if [[ `uname -a` == *ARCH* || `uname -a` == *MANJARO* ]]; then
    echo "Detected Arch-like disto."
    CHECK_PACKAGE="pacman -Q"
    INSTALL_PACKAGE="sudo pacman -S"
fi

TO_INSTALL=""
FAILED=0

function error { >&2 echo -e "${BR}$1${NC}"; }
function showinfo { echo -e "${BW}$1${NC}"; }
function ok { echo -e "${BG}$1${NC}"; }

function check_installed {
    echo "    Checking $1 ..."
    $1 --version > /dev/null
    if [ $? -ne 0 ]; then
        error "You dont have $1 installed."
        TO_INSTALL+=" $1"
        FAILED=1
    fi
}

function check_package {
    for pac in "$@"; do
        echo "    Checking package $pac ..."
        $CHECK_PACKAGE $pac > /dev/null
        if [ $? -ne 0 ]; then
            error "You dont have $pac installed."
            echo -e "Please run\n    $INSTALL_PACKAGE $pac\nto install."
            TO_INSTALL+=" $pac"
            FAILED=1
        fi
    done
}

function has_gxx_version {
    echo "    Checking g++ version is >= 4.8 ..."
    VERSION=$(g++ -dumpversion | sed -e 's/\.\([0-9][0-9]\)/\1/g' -e 's/\.\([0-9]\)/0\1/g' -e 's/^[0-9]\{3,4\}$/&00/')
    if [ 40800 -gt "$VERSION" ]; then
        error "g++ version too old, please install newer version, at least 4.8"
        TO_INSTALL+=' g++-4.8'
        FAILED=1
    fi
}

cwd=${PWD##*/}
if [ "$cwd" != "Grafi" ]; then
    echo -e "${BR}Run from Grafi/ directory in this project!${NC}"
    exit 1
fi

showinfo "Checking build tools ..."
check_installed g++
has_gxx_version
check_installed cmake
check_installed make
check_installed doxygen

# showinfo "Checking package dependencies ..."
# if [ $FAILED -eq 1 ]; then
#     error "Missing packages!"
#     echo -e "Run"
#     echo "    $INSTALL_PACKAGE $TO_INSTALL"
#     exit 1
# fi

# showinfo "Checking includes and links ..."
# TMPFILE=`mktemp --suffix=.cpp`
# rm $TMPFILE

# showinfo "Check libs ..."

if [ $FAILED -eq 0 ]; then
    ok "Configuring done."
else
    exit 1
fi
