#!/bin/sh
tar -xvf opcua-wsdl-${VERSION}.tar.gz
cd opcua-wsdl-${VERSION}
dh_make -y -m -c lgpl3 -e rykovanov.as@gmail.com -f ../opcua-wsdl-${VERSION}.tar.gz
dpkg-buildpackage -rfakeroot -nc -F ${DPKG_BUILDPACKAGE_OPTS}

