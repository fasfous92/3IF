#include <stdio.h>
#include <stdbool.h>
bool checkVertically( char* tab,int pos, int size);
bool checkDleft(int n, int m, char tab[n][m],int pos,int line);
bool checkHorizontally(int n, int m, char tab[n][m],int pos,int line);
bool checkDRight(int n, int m, char tab[n][m],int pos,int line);
char res(int n, int m, char tab[n][m]);
int main(){
        char tab[7][6];
        char tmp;
        int i,j;
        for (i=0;i<6;i++) {
            for (j=0;j<7;j++) {
                fscanf(stdin,"%c",&(tab[j][i]));
            }
            fscanf(stdin,"%c",&tmp); /* new line */
        }
  /*  for (i=0;i<6;i++) {
        for (j = 0; j < 7; j++) {
            printf("%c",tab[j][i]);
        }
        printf("\n");
    }*/


        printf("%c\n", res(7,6,tab));
        return 0;
}



bool checkHorizontally(int n, int m, char tab[n][m],int pos,int line){
        int succession=0;
        int i;
        for(i=pos;i>=0;i--){ //check left side we include the actual position as succession
            if(tab[i][line]==tab[pos][line]){
                succession++;
            }else{
                break;
            }
        }
        for(i=pos+1;i<n;i++){ //check the right side but we don't count the actual position (already did)
            if(tab[i][line]==tab[pos][line]){
                succession++;
            }else{
                break;
            }
        }
    if(succession>3){
        return true;
    }else
        return false;
}
bool checkVertically( char* tab,int pos, int size){
    int succession=0;
    int i;
    for(i=pos;i>=0;i--){ //check left side we include the actual position as succession
        if(tab[i]==tab[pos]){
            succession++;
        }else{
            break;
        }
    }
    for(i=pos+1;i<size;i++){ //check the right side but we don't count the actual position (already did)
        if(tab[i]==tab[pos]){
            succession++;
        }else{
            break;
        }
    }
    if(succession>3){
        return true;
    }else
        return false;
}
bool checkDleft(int n, int m, char tab[n][m],int pos,int line) {
    int i, j;
    int succession=0;
        if (pos==6) { //we can only try the checkDleft upwards
            i = line;
            j = pos;
            while (i >= 0 && j >= 0) {
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i--;
                j--;
            }
        }else if(pos==0){  //we can only try the checkDleft downwards
            i = line;
            j = pos;
            while (i <m && j <n) {
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i++;
                j++;
            }


        }else { //the rest of the cases need to be checked upwards and downwards
            i = line+1;
            j = pos+1;
            while (i < m && j < n) {//check of the downwards (we will not consider the actual position)
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i++;
                j++;
            }
            i=line;
            j=pos;
            while (i >= 0 && j >= 0) { //check of the upwards (we will consider the actual position)
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                }else {
                    break;
                   }
                i--;
                j--;

             }
        }
    if(succession>3){
        return true;
    } else
        return false;
}
bool checkDRight(int n, int m, char tab[n][m],int pos,int line) {
    int i, j;
    int succession = 0;
        if (pos == 0) { //we can only try the checkDleft upwards
            i = line;
            j = pos;
            while (i >= 0 && j <n) {
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i--;
                j++;
            }
        } else if (pos == 6) { //we can only try the checkDleft downwards
            i = line;
            j = pos;
            while (i < m && j >=0) {
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i++;
                j--;
            }


        } else { //the rest of the cases need to be checked upwards and downwards
            i = line + 1;
            j = pos - 1;
            while (i < m && j >=0) {//check of the downwards (we will not consider the actual position)
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i++;
                j--;
            }
            i = line;
            j = pos;
            while (i >=0 && j <n) { //check of the upwards (we will consider the actual position)
                if (tab[j][i] == tab[pos][line]) {
                    succession++;
                } else {
                    break;
                }
                i--;
                j++;

            }

    }
        if(succession>3){
            return true;
        } else
            return false;
}

char res(int n, int m, char tab[n][m]){
    int i,j;
    char c='0';
    for(i=0;i<m;i++) {
        for (j = 0; j < n; j++) {
            if (tab[j][i] != '0') {
                if ((!((j == 0 && i < 3) || (j == 6 && i > 2) || (i == 0 && j < 3) || (i == 5 && j > 3) ||
                      (j == 5 && i == 4) || (i == 1 && j == 1))) &&
                        (!(j == 6 && i < 3) || (j == 0 && i > 2) || (i == 0 && j > 3) || (j == 5 && i == 1) ||
                    (j == 1 && i == 4) || (i == 5 && j < 3))) { //can do Dleft and Dright
                    if (checkDRight(7, 6, tab, j, i) || checkDleft(7, 6, tab, j, i) ||
                        checkHorizontally(7, 6, tab, j, i) ||
                        checkVertically(tab[j], i, 6)) {

                        return tab[j][i];
                    }
                } else if (!((j == 0 && i < 3) || (j == 6 && i > 2) || (i == 0 && j < 3) || (i == 5 && j > 3) ||
                             (j == 5 && i == 4) || (i == 1 && j == 1))) {//can do Dright
                    if (checkDRight(7, 6, tab, j, i) || checkHorizontally(7, 6, tab, j, i) ||
                        checkVertically(tab[j], i, 6)) {

                        return tab[j][i];
                    }
                } else if (!(j == 6 && i < 3) || (j == 0 && i > 2) || (i == 0 && j > 3) || (j == 5 && i == 1) ||
                           (j == 1 && i == 4) || (i == 5 && j < 3)) { //can do Dleft
                    if (checkDleft(7, 6, tab, j, i) || checkHorizontally(7, 6, tab, j, i) ||
                        checkVertically(tab[j], i, 6)) {

                        return tab[j][i];
                    }
                } else {
                    if (checkHorizontally(7, 6, tab, j, i) || checkVertically(tab[j], i, 6)) {

                        return tab[j][i];
                    }
                }
            }
        }
    }
    return c;
}