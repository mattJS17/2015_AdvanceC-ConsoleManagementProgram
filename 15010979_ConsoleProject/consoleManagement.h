#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************** declaration of constants
#define TRUE			1		// 1을 TRUE로 정의한다.
#define FALSE			0		// 0을 FALSE로 정의한다.

#define INSERT			1		// switch문에서 1을 누르면 INSERT메뉴가 나오도록 1을 INSERT으로 정의한다.
#define REMOVE		2		// switch문에서 2을 누르면 REMOVE메뉴가 나오도록 2를 REMOVE로 정의한다.
#define UPDATE		3		// switch문에서 3을 누르면 UPDATE메뉴가 나오도록 3을 UPDATE로 정의한다.
#define RETRIEVE		4		// switch문에서 4을 누르면 RETRIEVE메뉴가 나오도록 4를 RETRIEVE로 정의한다.
#define PRINT			5		// switch문에서 5을 누르면 PRINT메뉴가 나오도록 5를 PRINT로 정의한다.
#define INIT				6		// switch문에서 6을 누르면 INIT메뉴가 나오도록 6를 INIT로 정의한다.
#define READ			7
#define WRITE			8
#define ABOUT			9		// switch문에서 9을 누르면 ABOUT메뉴가 나오도록 9를 ABOUT로 정의한다.
#define EXIT				0		// switch문에서 0을 누르면 EXIT이 되도록 0을 EXIT으로 정의한다.


// Insert Menu Constants
#define NONE				0		// Insert Menu의 초기화면에서 0을 누르면 메인메뉴로 돌아가도록 0을 NONE으로 정의한다.
#define ORDERED			1		// Insert Menu의 초기화면에서 1을 누르면 Orderedlist로 설정하도록 1을 ORDERED으로 정의한다.
#define UNORDERED		2		// Insert Menu의 초기화면에서 2를 누르면 Unorderedlist로 설정하도록 2을 UNORDERED으로 정의한다.

#define FIRST_NODE		1		// Unorderedlist에서 1을 누르면 first node방식으로 값을 입력받는다
#define RANDOM_NODE	2		// Unorderedlist에서 2을 누르면 random node방식으로 값을 입력받는다
#define LAST_NODE		3		// Unorderedlist에서 3을 누르면 last node방식으로 값을 입력받는다

// Remove Menu Constants
#define DATA				1			// Remove Menu에서 1을 누르면 값을 입력받아 그 값을 list에서 지운다
#define POSITION		2			// Remove Menu에서 2를 누르면 위치를 입력받아 그 위치에 있던 값을 list에서 지운다

// Update Menu Constants

// Print Menu Constants
#define PREVIOUS		0			// Print Menu에서 0을 누르면 Main Menu화면으로 돌아간다
#define SEQUENCE		1			// Print Menu에서 1을 누르면 SEQUENCE방식으로 list를 출력한다
#define REVERSE		2			// Print Menu에서 2을 누르면 REVERSE방식으로 list를 출력한다

// Read/Write Menu Constants
#define TEXT			1
#define BINARY			2

// write Menu Constants
#define DATA_ONLY			1
#define OUTPUT_FORMAT	2

//************** declaration of datas
typedef struct _ListNode {

	// data field
	int data;

	// link field
	struct _ListNode * link;

}ListNode;						// node를 만드는 구조체이다. int data로 node에 데이터를 저장하는 data field를 선언하고, 
// struct _ListNode * link로 다음 node를 가르키는 포인터의 값을 저장하는 link field를 선언한다.  

// header pointer
ListNode * pHeader;				// 연결체의 첫번째 노드를 가르키는 포인터이다.

//************** Global variables
int g_nInsertType;				// g_ -> 전역변수라는 뜻, ordered이냐 unordered인지를 구분하기 위해 있음. case -> 3가지임(ordered, unordered, 앞으로 계속 출력될것)

//************** declaration of functions

int displayMainMenu();			
/*	function name : displayMainMenu
	pre condition : none
	post condition : 입력한 메뉴가 뜨도록 하기 위해 사용자가 입력한 번호를 main함수의 switch문으로 보낸다
	function : management 메뉴창을 띄워서 사용자로 하여금 insert menu, remove memu, update menu, 
				retrieve menu, print menu, exit 중 하나를 고르게 한다.
*/

//************** insert menu functions

void insertMenu();			
/*	function name : insertMenu()
	pre condition : nSelectedMainMenu의 값이 1이다
	post condition : 1,2 중 하나의 값을 입력받는다
	function : 0을 입력하면 메인 메뉴로 돌아가고 1을 누르면 insertToOrderedList을 실행시키고 2를 누르면 insertToUnorderedMenu를 실행시킨다. 
				g_nInsertType을 변수로 둬서 한번 방식을 정하면 계속 그 방식만 나옴으로 이 함수를 insert menu의 초기설정화면이다
*/	

void insertToOrderedList();			
/*	function name : insertToOrderedList()
	pre condition : g_nInsertType의 값이 1이다.
	post condition : node
	function : 값을 입력받으면 그것을 오름차순으로 정리해서 연결체에 넣는다
*/


void insertToUnorderedMenu();	
/*	function name : insertToUnorderedMenu()
	pre condition : g_nInsertType의 값이 2이다.
	post condition : 1,2,3 중 하나의 값을 입력받는다
	function : 0을 입력하면 메인 메뉴로 돌아가고 1,2,3 중 하나를 누르면 그 값을 insertToUnorderedList로 전달해 준다 
*/

void insertToUnorderedList(int option);		
/*	function name : insertToUnorderedListntList(int option)
	pre condition : insertToUnorderedMenu에서 nMenu의 값이 1,2,3 중 하나이다
	post condition : node
	function : FIRST NODE : 입력받은 값을 들어온 순서대로 연결체를 만드는 것이다. 가장 최근 데이터가 가장 앞에 있다.
				RANDOM NODE : 사용자가 원하는 위치를 입력하면 그 위치에 노드를 삽입한다
				LAST NODE : FIRST NODE와 반대로 입력받은 값을 연결체의 가장 끝에 삽입한다. 가장 오래된 데이터가 가장 앞에 있다.
*/

//************** remove menu functions

void removeMenu();		
/*	function name : removeMenu()
	pre condition : nSelectedMainMenu의 값이 2이다
	post condition : 1또는 2를 눌러 case문을 실행시켜 removeData() 또는 removePosition()를 실행시킨다
	function : 노드를 제거할 때 그것을 제거할 방식을 고르는 함수이다. 데이터로 노드를 찾아 지우겠다고 하면 switch문에서 removeData()를 실행시키고 위치로 지우겠다고 하면 removePosition()을 실행시킨다
*/

void removeData();	
/*	function name : removeData()
	pre condition : removeMenu()에서 nRemoveMenu의 값이 1이다.
	post condition : none
	function : 지우고 싶은 노드의 데이터를 입력하면 연결체에서 그 노드를 모두 삭제한다(중복 삭제)
*/

void removePosition();
/*	function name : removePosition()
	pre condition : removeMenu()에서 nRemoveMenu의 값이 2이다.
	post condition : none
	function : 지우고 싶은 노드의 위치를 입력하면 연결체에서 그 위치에 있는 노드를 삭제한다.
*/

//************** update menu functions

void updateMenu();	
/*	function name : updateMenu()
	pre condition : nSelectedMainMenu의 값이 3이다
	post condition : nUpdateMenu의 값이 1 또는 2이다.
	function : 노드를 제거할 때 그것을 제거할 방식을 고르는 함수이다. 데이터로 노드를 찾아 수정하겠다고 하면 switch문에서 updateData()를 실행시키고 위치로 수정하겠다고 하면 updatePosition()을 실행시킨다
*/

void updateData();		
/*	function name : updateData()
	pre condition : nMenu의 값이 1,2,3 중 하나이다
	post condition : none
	function : 수정하고 싶은 데이터의 기존값과 수정값을 입력하면 기존값을 갖고있는 노드를 찾아 값을 수정한다
*/

void updatePosition();		

//************** retrieve menu functions

void retrieveMenu();	

//************** print menu functions

void printMenu();				
/*	function name : printList()
	pre condition : nSelectedMainMenu의 값이 5이다
	post condition : nMenu의 값이 1또는 2여야한다.
	function : printMenu 창을 띄워서 사용자의 입력을 받는다.
*/

void printList(int option);		
/*	function name : printList(int option)
	pre condition : printList()에서 nMenu의 값이 1이거나 2이다.
	post condition : none
	function : printMenu에서 1을 눌렀으면 SEQUENCE방식으로 리스트를 출력하고, 2를 눌렀으면 REVERSE방식으로 출력한다.
*/
void recursiveList(ListNode * pVisited);

//************** init menu functions

void initFunc();		
/*	function name : initFunc()
	pre condition : nSelectedMainMenu의 값이 6이다
	post condition : none
	function : 쉽게 말하면 이 콘솔메뉴프로그램을 공장초기화시키는 함수이다. 연결체에 있는 모든 노드를 삭제하고, 정해졌던 insertMenu()를 초기설정화면으로 바꾼다 
	*/

//************** about menu functions

void about();				
/*	function name : about()
	pre condition : nSelectedMainMenu의 값이 9이다
	post condition : none
	function : 이 콘솔메뉴를 만든 사람, 저작권 등에 대해 설명한다.
	*/

//************** read/write menu functions

void readMenu();
void readTextFile();
void readBinaryFile();
int checkBeforeRead();

void writeMenu();
void writeTextFile();
void writeBinaryFile();



