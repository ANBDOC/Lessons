#!/bin/bash
#===============================================================================
#
#          FILE:  swift.sh
# 
#         USAGE:  ./swift.sh 
# 
#   DESCRIPTION: Install Swift Programm language 
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR:  Alexandr Barnakov (Mr), anb.box@outlook.com
#       COMPANY:  RTI
#       VERSION:  1.0
#       CREATED:  06.07.2021 10:20:53 MSK
#      REVISION:  ---
#===============================================================================

apt-get install \
    binutils \
    git \
    gnupg2 \
    libc6-dev \
    libcurl4 \
    libedit2 \
    libgcc-9-dev \
    libpython2.7 \
    libsqlite3-0 \
    libstdc++-9-dev \
    libxml2 libz3-dev \
    pkg-config \
    tzdata \
    zlib1g-dev -y

wget https://swift.org/builds/swift-5.3.3-release/ubuntu2004/swift-5.3.3-RELEASE/swift-5.3.3-RELEASE-ubuntu20.04.tar.gz
wget https://swift.org/builds/swift-5.3.3-release/ubuntu2004/swift-5.3.3-RELEASE/swift-5.3.3-RELEASE-ubuntu20.04.tar.gz.sig

gpg --keyserver hkp://pool.sks-keyservers.net --recv-keys '7463 A81A 4B2E EA1B 551F FBCF D441 C977 412B 37AD' '1BE1 E29A 084C B305 F397 D62A 9F59 7F4D 21A5 6D5F' 'A3BA FD35 56A5 9079 C068 94BD 63BC 1CFE 91D3 06C6' '5E4D F843 FB06 5D7F 7E24 FBA2 EF54 30F0 71E1 B235' '8513 444E 2DA3 6B7C 1659 AF4D 7638 F1FB 2B2B 08C4' 'A62A E125 BBBF BB96 A6E0 42EC 925C C1CC ED3D 1561' '8A74 9566 2C3C D4AE 18D9 5637 FAF6 989E 1BC1 6FEA'

gpg --verify swift-5.3.3-RELEASE-ubuntu20.04.tar.gz{.sig,}

tar -xvzf swift-5.3.3-RELEASE-ubuntu20.04.tar.gz
mv swift-5.3.3-RELEASE-ubuntu20.04 /opt/swift
echo "export PATH=/opt/swift/usr/bin:$PATH" >> ~/.bashrc
source ~/.bashrc
swift --version

swift
"""
1> let name = "Hitesh Jethva"
name: String = "Hitesh Jethva"
  2> import Glibc // imports GNU C Library
  3> var ln = random() % 100
ln: Int = 83
  4> print("hello,",name,"your lucky number is", ln)
hello, Hitesh Jethva your lucky number is 83

:q - exit
""""
