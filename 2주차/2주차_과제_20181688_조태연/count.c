#include "Header.h"

void count_num(int n,int num[]){

        for(int i=1;i<=n;i++){ //1~N까지 세주기 위한 for문
                
                int d=i; //i값은 for문 돌리기 위한 값으로만 쓰기 위해서 d로 옮겨주고 d를 이용
                while(d>0){

                        int tmp=d%10; //1의 자리수만 세기 위한 tmp
                        num[tmp]++; //해당 배열의 값을 1씩 키워줌
                        d/=10; //다음 자리수 계산을 위해 1의 자리 수를 버려야해서 10으로 나눠줌
                }
        }
}
