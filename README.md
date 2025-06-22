# Advaned ST7920 Clock
<img src="https://github.com/user-attachments/assets/e17693f7-ce15-4401-b33e-15adab952ca6" width="400"/><br>
쓸만한 ST7920 시계

# 요구 사항
* u8g2
* RTClib

* ST7920 128x64 디스플레이
* DS3231 RTC

# 기능
* 현재 날짜와 요일 표시
* 오전/오후 표시
* 초시계
* 멀쩡한 UI 디자인
* 수능까지 남은 날짜 표시(이미지에서는 하루 적게 표시되는 버그가 있습니다. 코드에서는 고쳐져 있는 상태입니다.)

# 연결 방법
## ST7920 LCD
|핀 번호|핀 이름|연결|
|--|--|--|
 | 1 | GND| GND|
 | 2 | VCC |5V|
 | 4 | RS | CS(SPI) |
 | 5 | R/W |  MOSI |
 | 6 | E | SCK |
 | 15 | PSB | 0(SPI 모드) |
 | 19 | BLA | 적절한 저항을 거쳐서 5V |
 | 20 | BLK | GND |
 
## DS3231 RTC
|핀 이름|연결|
|--|--|
| GND| GND|
| VCC | 5V |
| SCL | SCL |
| SDA | SDA |

일부 중국제 모듈에서는 역충전 문제가 있기 때문에 다이오드를 부숴야 합니다.
# 라이선스
GPL 3.0

