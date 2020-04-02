


<p align="center">
<img src="https://www.etoland.co.kr//data/daumeditor02/191201/thumbnail3/75663115751638450.png" width="50%" height="50%"></p>


# 1. function 설명



### 	1. ft_atoi, ft_putnbr, ft_putstr : 기본 함수들

- 기존의 libft 혹은 C Piscine에서의 그 함수들과 **큰 차이 없음**. 




### 	2.  ft_error_msg, ft_digit_len, ft_error_handle : 에러 처리부분



- ft_error_msg: 에러 메시지 출력 후 프로그램 종료


- ft_digit_len : 앞부분의 0을 제외한 숫자의 자릿수 측정( 000306은 306으로 3자리)


- ft_error_handle 하단의 Error handling의 에러들을 처리




### 	3. ft_even_to_odd, ft_prime_factors : 드디어 소인수분해 시작



- ft_even_to_odd:  들어온 숫자 n을 짝수인지 검사해서 짝수이면 2를 출력하고 숫자를 2로 나눔.
  ​								occurred_before라는 flag를 이용해서 한번만 출력되도록 설정.
  ​								짝수를 먼저 처리하는 이유는 뒤에 나오는 ft_prime_factors가 홀수만 검사함으로써 계산 시간 단축

  

- ft_prime_factors: n이 2이외의 숫자로 나누어 지는지 3부터 차례대로 검사함.
  ​								짝수는 위에서 검사가 끝났기 때문에 3,5,7,9 식으로 홀수들만 검사함.
  ​								이 때 sqrt(n)까지만 검사함으로써 계산 시간 단축



#### Time complexity : O(sqrt(n))



# 2. Error handling

### 	1. 인자가 없거나 2개 이상 들어올 때:

 		  `"Enter only one argument"` 출력


### 	2. 들어온 인자가 숫자만으로 이루어지지 않았을 때( '-' 기호 포함):

​		   `"Enter only a positive number"` 출력

### 	3. 자릿수가 10자리 넘을 때:

​		   `"Enter a number less than or equal to 4294967295"` 출력

​		   <u>다만, 앞에 0이 여러개 있을 경우 0을 무시하고 자릿수를 셈</u>
​		   <u>예를 들어 0000000306 = 306으로 3자리로 계산함</u>

### 	4. 10자리 이하의 숫자를 long long 숫자형으로 변환 후 2^32-1보다 클 때:

​		   `"Enter a number less than or equal to 4294967295 (= 2^32-1)"` 출력

### 	5. 마찬가지로 2보다 작을 때

 		  `"Enter a number greater than or equal to 2"` 출력





**들어오는 인자가 10자리인지 검사하는 이유는 long long자료형으로 담지 못하는 숫자인 경우를 제거하기 위함임.*

**unsigned int를 사용하지 않고 long long을 사용하는 이유는 10자리 이내이지만 2^32-1 (= 4294967295) 보다 큰 숫자를 변수로 받지 못함을 방지하기 위함임.*



# 3. 사용법

- `make`

- `./factorization 숫자` 

  예) `./factorization 132`

