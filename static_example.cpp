/********************************************************************************************
 *
 * [정적 변수] 클래스의 모든 멤버 변수와 멤버 함수는 정적(static)으로 정의 될 수 있음
 * 정적 멤버 변수 : 인스턴스가 생성 될 때마다 독립적으로 생기는 멤버 변수와 달리,
 * 해당 클래스에 하나만 생성, 모든 인스턴스에서 공동 접근 가능
 * 정적 멤버 함수 : 클래스 당 하나만 생기며 모든 인스턴스에서 공동으로 호출 가능
 *
 * (주의) 정적 맴버의 초기화는 클래스 내부에서 불가
 *
 * 정적 변수의 접근
 * 	(1) 이름으로 접근 - 클래스명::변수명
 * 	(2) 인스턴스를 통해서 접근  - 인스턴스명.변수면
 *
 * (주의) 정적 멤버 함수에서는 오직 정적 변수, 정적 함수만 사용 가능
 *
 *
 * ******(결과값)*****************************************************************************
 * 
 * [Led 클래스]생성자 호출 | 클래스 수: 1
 * [Led 클래스]생성자 호출 | 클래스 수: 2
 * 정적 변수 이름으로 접근 (Led::iCount)  2
 * [Led 클래스]생성자 호출 | 클래스 수: 3
 * 정적 변수 인스턴스로 접근 (myLed.iCount)  3
 * 정적 함수의 호출 (Led::getDoubledCount())  6
 * 정적 함수의 호출 (myLed.getDoubledCount())  6
 * [Led 클래스]소멸자 호출 | 클래스 수: 2
 * [Led 클래스]소멸자 호출 | 클래스 수: 1
 * [Led 클래스]소멸자 호출 | 클래스 수: 0
 *
 * ******************************************************************************************/


#include <iostream>
using namespace std;

class Led {
	public:
		//생성자
		Led() {
			iCount++;
			cout << "[Led 클래스]생성자 호출 | 클래스 수: " << iCount << endl;
		}
		//소멸자
		~Led() {
			iCount--;
			cout << "[Led 클래스]소멸자 호출 | 클래스 수: " << iCount << endl;
		}
		void turnOn();
		void turnOff();
		static int iCount;	//정적 변수
		//이 경우 애러가 발생 ( error: ISO C++ forbids in-class initialization of non-const static member ‘Led::iCount’)
		//static int iCount=0;
		
		static int getDoubledICount () {
			return iCount*2;
		}
};

//정적 변수는 외부에서 초기화 시킴
int Led::iCount=0;

int main (void) {

	Led myLed;	//생성자의 호출	
	Led myLed2;

	cout << "정적 변수 이름으로 접근 (Led::iCount)  " << Led::iCount << endl;

	Led myLed3;
	
	cout << "정적 변수 인스턴스로 접근 (myLed.iCount)  " << myLed.iCount << endl;
	cout << "정적 함수의 호출 (Led::getDoubledCount())  " << Led::getDoubledICount() << endl;
	cout << "정적 함수의 호출 (myLed.getDoubledCount())  " << myLed.getDoubledICount() << endl;
	
	return 0;
}
