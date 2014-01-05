#!/bin/sh
tar -xvf opcua-wsdl-0.1.2.tar.gz
#cp exe/configs/opcuaserver opcuaserver-0.1.2/debian/opcuaserver.init
cd opcua-wsdl-0.1.2
dh_make -y -m -c lgpl3 -e rykovanov.as@gmail.com -f ../opcua-wsdl-0.1.2.tar.gz
dpkg-buildpackage -rfakeroot $*

