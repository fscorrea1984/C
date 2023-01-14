#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {

  uid_t uid;
  gid_t gid;

  gid = getegid();
  uid = geteuid();

  setresgid(gid,gid,gid);
  setresuid(uid,uid,uid);

  system("/bin/bash");

}
