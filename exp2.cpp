#!/bin/bash

echo "------------------------------------------"
echo "SYSTEM INFORMATION REPORT"
echo "------------------------------------------"

# a) Display OS version, release number, and kernel version
echo "1. Operating System Details:"
echo -n "   OS Version/Release: "
lsb_release -d | cut -f2
echo -n "   Kernel Version: "
uname -r
echo ""

# b) Display top 10 processes in descending order of CPU usage
echo "2. Top 10 Processes by CPU Usage:"
ps -eo pid,ppid,cmd,%cpu --sort=-%cpu | head -n 11
echo ""

# c) Display processes with highest memory usage
echo "3. Processes with Highest Memory Usage:"
ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 6
echo ""

# d) Display current logged-in user and login name
echo "4. User Information:"
echo "   Current User: $USER"
echo "   Login Name: $(whoami)"
echo "------------------------------------------"