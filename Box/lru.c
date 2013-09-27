#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define getIdx(c) (c - 'a')

//char *key;
//char *value;
int mxLruSize = 1e6+111, lruSize = 0;
char *timeLine[(int)1e6+111] = {};
int startTime = 0, curTime = 0, tmpIdx;
int modifyTimeline;

struct Node {/*{{{*/
  struct Node *child[26];
  char *value;
  int isWord, prefixCnt, accessTime;
}*root;/*}}}*/

void init(struct Node *nd) {/*{{{*/
  memset(nd->child, 0, sizeof(struct Node *)*26);
  nd->value = NULL;
  nd->isWord = nd->prefixCnt = 0;
  nd->accessTime = -1;
}/*}}}*/

int insert(char *key,char *value, int id, struct Node *nd) {/*{{{*/
  if(key[id] =='\0') {
    nd->value = value;
    if(nd->isWord) {
      //updateTimeline(nd->accessTime);
      timeLine[curTime] = key;
      timeLine[nd->accessTime] = NULL;
      //printf("Movin %s to time = %d from (%d, %s)\n", timeLine[curTime], curTime, nd->accessTime, timeLine[nd->accessTime]);
      nd->accessTime = curTime;
      curTime++;
      return 0;
    }
    else {
      nd->prefixCnt++;
      nd->isWord = 1;
      timeLine[curTime] = key;
      //printf("Inserting %s at time = %d\n", timeLine[curTime], curTime);
      nd->accessTime = curTime;
      curTime++;
      lruSize++;
      return 1;
    }
  }
  int idx = getIdx(key[id]);
  if(nd->child[idx] == NULL) {
    nd->child[idx] = (struct Node*)malloc(sizeof (struct Node));
    init(nd->child[idx]);
  }
  int ret = insert(key, value, id+1, nd->child[idx]);
  nd->prefixCnt+=ret;
  return ret;
}/*}}}*/

void removeKey(char *key, int id, struct Node *nd) {/*{{{*/
  nd->prefixCnt--;
  if(key[id] == '\0') {
    nd->isWord = 0;
    timeLine[nd->accessTime] = NULL;
    nd->accessTime = -1;
    lruSize--;
    return;
  }
  tmpIdx = getIdx(key[id]);
  removeKey(key, id+1, nd->child[tmpIdx]);
}/*}}}*/

void resize() {/*{{{*/
  //printf("\nlruSize = %d, mxLruSize = %d\n", lruSize, mxLruSize);
  while(lruSize > mxLruSize) {
    if(timeLine[startTime] != NULL) {
      //printf("Remvoing: %s at time = %d\n", timeLine[startTime], startTime);
      char *key = timeLine[startTime];
      removeKey(key, 0, root);
    }
    startTime++;
  }
}/*}}}*/

void display(char *key, int id, struct Node *nd) {/*{{{*/
  assert(nd->prefixCnt >= 0);
  if(nd->prefixCnt==0)
    return;
  if(nd->isWord) {
    printf("%s %s\n", key, nd->value);
    //printf("%s %s %d\n", key, nd->value, nd->accessTime);
  }
  int i;
  for(i = 0; i < 26; i++) if(nd->child[i] != NULL) {
    key[id] = (char) (i+'a');
    display(key, id+1, nd->child[i]);
    key[id] = '\0';
  }
}/*}}}*/

void getValue(char *key, int id, struct Node *nd) {/*{{{*/
  if(key[id] == '\0') {
    if(nd->isWord) {
      if(modifyTimeline) {
        //printf("Movin (%s=%s, %s) to time = %d from %d\n", key, timeLine[nd->accessTime], nd->value, curTime, nd->accessTime);
        timeLine[curTime] = timeLine[nd->accessTime];
        timeLine[nd->accessTime] = NULL;
        nd->accessTime = curTime;
        //printf("Old values: (%d, %s), new values: (%d, %s)\n", nd->accessTime, timeLine[nd->accessTime], curTime, timeLine[nd->accessTime]);
        curTime++;
      }
      printf("%s\n", nd->value);
      return;
    }
    else {
      printf("NULL\n");
      return;
    }
  }

  tmpIdx = getIdx(key[id]);
  if(nd->child[tmpIdx] == NULL) {
    printf("NULL\n");
    return;
  }
  getValue(key, id+1, nd->child[tmpIdx]);
}/*}}}*/

int main()
{
  root = (struct Node*) malloc(sizeof (struct Node));
  init(root);

  int test;
  char action[12];
  char *key, *value;

  scanf("%d", &test);

  while(test--) {
    scanf("\n%s", action);
    //printf("%s: ", action);

    if(action[0] == 'B') {
      scanf(" %d", &mxLruSize);
      //printf("%d", mxLruSize);
      resize();
    }
    else if(action[0] == 'S') {
      key = (char*)malloc(12*sizeof(char));
      value = (char*)malloc(12*sizeof(char));
      scanf("%s %s", key, value);
      //printf("%s %s\n", key, value);
      insert(key, value, 0, root);
      resize();
    }
    else if(action[0] == 'P') {
      key = (char*)malloc(12*sizeof(char));
      scanf(" %s", key);
      //printf("%s\n", key);
      modifyTimeline=0;
      getValue(key, 0, root);
      //printf("%s\n", value == NULL? "NULL": value);
    }
    else if(action[0] == 'G') {
      key = (char*)malloc(12*sizeof(char));
      scanf(" %s", key);
      //printf("%s\n", key);
      modifyTimeline=1;
      getValue(key, 0, root);
      //printf("%s\n", value == NULL? "NULL": value);
    }
    else if(action[0] == 'D') {
      resize();
      //printf("\n");
      key = (char*)malloc(12*sizeof(char));
      display(key, 0, root);
    }
    else
      assert(0);

    /*
    printf("\n-------------\n");

    key = (char*)malloc(12*sizeof(char));
    display(key, 0, root);
    printf("\n");
    int i;
    for(i = (int)startTime; i < (int)curTime; ++i) if(timeLine[i] != NULL){
      printf("%d: %s\n", i, timeLine[i]);
    }
    printf("\n-------------\n");
    */
  }

  return 0;
}

