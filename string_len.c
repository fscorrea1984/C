// 2021-05-10 by unkw
int string_len(char *str) {
        int i=-1;
        while (str[++i] != 0);
        return i;
}
