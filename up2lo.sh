#!/bin/sh

#
# up2lo - rename files from uppercase to lower case.
#
for i in $*
do
   file=`echo $i | tr "[A-Z]" "[a-z]"`
   mv $i $file
done

