#!/bin/bash

TEMP_PATH=$0
echo $TEMP_PATH
ROOT_DIR_PATH=${TEMP_PATH%/*}
echo $ROOT_DIR_PATH
BAEKJOON_DIR_PATH=$ROOT_DIR_PATH/baekjoon
TXT_PATH=$ROOT_DIR_PATH/suffix.txt
NEW_FILE_NAME=P$(cat $TXT_PATH).java
touch $BAEKJOON_DIR_PATH/P$(cat $TXT_PATH).java
NEW_FILE_PREFIX=${NEW_FILE_NAME%.*}
echo class $NEW_FILE_PREFIX {} > $BAEKJOON_DIR_PATH/$NEW_FILE_NAME
echo $(( $(cat $TXT_PATH) + 1 )) > $TXT_PATH
git pull --rebase
git add $BAEKJOON_DIR_PATH/$NEW_FILE_NAME
git commit -m "Wip $NEW_FILE_PREFIX"
git push origin main:main