#!/bin/bash

mkdir $1

cd $1

git init

mkdir bin include lib share man info

echo $1 > README.md

mkdir  .gitignore

git add .

git commit -m "Create initial structure."


