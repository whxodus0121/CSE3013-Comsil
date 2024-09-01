//입력을 받고 다른 함수를 호출
#include "Header.h"

int main(void){

        int t;
        scanf("%d",&t); //테스트케이스 t를 입력

        while(t--){
        

                int num[10]={0,}; //숫자의 개수를 배열에 저장하기 위해 선언하고 테스트케이스마다 새로 개수를 세기 위해서 테스트케이스마다 새로 초기화
                int n;
                
                scanf("%d",&n); // n을 입력
                count_num(n,num); // 숫자 개수를 세주는 함수인 count_num을 호출
                print_count(num); // 완성된 num배열을 출력해주는 함수인 print_count를 호출
        }

        return 0;
}
