#!/bin/bash
#Filename: hook.sh 

executeCppChecker () 
{
  cppFiles=$(git diff --name-only origin/master..master | grep --regexp "^.*\.\(c\|cpp\|cc\)$")

  for eachFile in $cppFiles
  do
    if cppcheck -j 1 --error-exitcode=1 $eachFile; then
      printf "$eachFile is correct\n\n"
    else
      printf "There's an error in $eachFile.\n"
      printf "NOT pushing.\n\n"
      exit 1
    fi
  done

  printf "Now continue to push.\n\n"

  #if ("$ret" -eq '1') then
  #  return 1
  #else
  #  return 0;
  #fi
}

executeCppChecker;
