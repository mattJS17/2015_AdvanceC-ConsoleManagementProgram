#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************** declaration of constants
#define TRUE			1		// 1�� TRUE�� �����Ѵ�.
#define FALSE			0		// 0�� FALSE�� �����Ѵ�.

#define INSERT			1		// switch������ 1�� ������ INSERT�޴��� �������� 1�� INSERT���� �����Ѵ�.
#define REMOVE		2		// switch������ 2�� ������ REMOVE�޴��� �������� 2�� REMOVE�� �����Ѵ�.
#define UPDATE		3		// switch������ 3�� ������ UPDATE�޴��� �������� 3�� UPDATE�� �����Ѵ�.
#define RETRIEVE		4		// switch������ 4�� ������ RETRIEVE�޴��� �������� 4�� RETRIEVE�� �����Ѵ�.
#define PRINT			5		// switch������ 5�� ������ PRINT�޴��� �������� 5�� PRINT�� �����Ѵ�.
#define INIT				6		// switch������ 6�� ������ INIT�޴��� �������� 6�� INIT�� �����Ѵ�.
#define READ			7
#define WRITE			8
#define ABOUT			9		// switch������ 9�� ������ ABOUT�޴��� �������� 9�� ABOUT�� �����Ѵ�.
#define EXIT				0		// switch������ 0�� ������ EXIT�� �ǵ��� 0�� EXIT���� �����Ѵ�.


// Insert Menu Constants
#define NONE				0		// Insert Menu�� �ʱ�ȭ�鿡�� 0�� ������ ���θ޴��� ���ư����� 0�� NONE���� �����Ѵ�.
#define ORDERED			1		// Insert Menu�� �ʱ�ȭ�鿡�� 1�� ������ Orderedlist�� �����ϵ��� 1�� ORDERED���� �����Ѵ�.
#define UNORDERED		2		// Insert Menu�� �ʱ�ȭ�鿡�� 2�� ������ Unorderedlist�� �����ϵ��� 2�� UNORDERED���� �����Ѵ�.

#define FIRST_NODE		1		// Unorderedlist���� 1�� ������ first node������� ���� �Է¹޴´�
#define RANDOM_NODE	2		// Unorderedlist���� 2�� ������ random node������� ���� �Է¹޴´�
#define LAST_NODE		3		// Unorderedlist���� 3�� ������ last node������� ���� �Է¹޴´�

// Remove Menu Constants
#define DATA				1			// Remove Menu���� 1�� ������ ���� �Է¹޾� �� ���� list���� �����
#define POSITION		2			// Remove Menu���� 2�� ������ ��ġ�� �Է¹޾� �� ��ġ�� �ִ� ���� list���� �����

// Update Menu Constants

// Print Menu Constants
#define PREVIOUS		0			// Print Menu���� 0�� ������ Main Menuȭ������ ���ư���
#define SEQUENCE		1			// Print Menu���� 1�� ������ SEQUENCE������� list�� ����Ѵ�
#define REVERSE		2			// Print Menu���� 2�� ������ REVERSE������� list�� ����Ѵ�

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

}ListNode;						// node�� ����� ����ü�̴�. int data�� node�� �����͸� �����ϴ� data field�� �����ϰ�, 
// struct _ListNode * link�� ���� node�� ����Ű�� �������� ���� �����ϴ� link field�� �����Ѵ�.  

// header pointer
ListNode * pHeader;				// ����ü�� ù��° ��带 ����Ű�� �������̴�.

//************** Global variables
int g_nInsertType;				// g_ -> ����������� ��, ordered�̳� unordered������ �����ϱ� ���� ����. case -> 3������(ordered, unordered, ������ ��� ��µɰ�)

//************** declaration of functions

int displayMainMenu();			
/*	function name : displayMainMenu
	pre condition : none
	post condition : �Է��� �޴��� �ߵ��� �ϱ� ���� ����ڰ� �Է��� ��ȣ�� main�Լ��� switch������ ������
	function : management �޴�â�� ����� ����ڷ� �Ͽ��� insert menu, remove memu, update menu, 
				retrieve menu, print menu, exit �� �ϳ��� ���� �Ѵ�.
*/

//************** insert menu functions

void insertMenu();			
/*	function name : insertMenu()
	pre condition : nSelectedMainMenu�� ���� 1�̴�
	post condition : 1,2 �� �ϳ��� ���� �Է¹޴´�
	function : 0�� �Է��ϸ� ���� �޴��� ���ư��� 1�� ������ insertToOrderedList�� �����Ű�� 2�� ������ insertToUnorderedMenu�� �����Ų��. 
				g_nInsertType�� ������ �ּ� �ѹ� ����� ���ϸ� ��� �� ��ĸ� �������� �� �Լ��� insert menu�� �ʱ⼳��ȭ���̴�
*/	

void insertToOrderedList();			
/*	function name : insertToOrderedList()
	pre condition : g_nInsertType�� ���� 1�̴�.
	post condition : node
	function : ���� �Է¹����� �װ��� ������������ �����ؼ� ����ü�� �ִ´�
*/


void insertToUnorderedMenu();	
/*	function name : insertToUnorderedMenu()
	pre condition : g_nInsertType�� ���� 2�̴�.
	post condition : 1,2,3 �� �ϳ��� ���� �Է¹޴´�
	function : 0�� �Է��ϸ� ���� �޴��� ���ư��� 1,2,3 �� �ϳ��� ������ �� ���� insertToUnorderedList�� ������ �ش� 
*/

void insertToUnorderedList(int option);		
/*	function name : insertToUnorderedListntList(int option)
	pre condition : insertToUnorderedMenu���� nMenu�� ���� 1,2,3 �� �ϳ��̴�
	post condition : node
	function : FIRST NODE : �Է¹��� ���� ���� ������� ����ü�� ����� ���̴�. ���� �ֱ� �����Ͱ� ���� �տ� �ִ�.
				RANDOM NODE : ����ڰ� ���ϴ� ��ġ�� �Է��ϸ� �� ��ġ�� ��带 �����Ѵ�
				LAST NODE : FIRST NODE�� �ݴ�� �Է¹��� ���� ����ü�� ���� ���� �����Ѵ�. ���� ������ �����Ͱ� ���� �տ� �ִ�.
*/

//************** remove menu functions

void removeMenu();		
/*	function name : removeMenu()
	pre condition : nSelectedMainMenu�� ���� 2�̴�
	post condition : 1�Ǵ� 2�� ���� case���� ������� removeData() �Ǵ� removePosition()�� �����Ų��
	function : ��带 ������ �� �װ��� ������ ����� ���� �Լ��̴�. �����ͷ� ��带 ã�� ����ڴٰ� �ϸ� switch������ removeData()�� �����Ű�� ��ġ�� ����ڴٰ� �ϸ� removePosition()�� �����Ų��
*/

void removeData();	
/*	function name : removeData()
	pre condition : removeMenu()���� nRemoveMenu�� ���� 1�̴�.
	post condition : none
	function : ����� ���� ����� �����͸� �Է��ϸ� ����ü���� �� ��带 ��� �����Ѵ�(�ߺ� ����)
*/

void removePosition();
/*	function name : removePosition()
	pre condition : removeMenu()���� nRemoveMenu�� ���� 2�̴�.
	post condition : none
	function : ����� ���� ����� ��ġ�� �Է��ϸ� ����ü���� �� ��ġ�� �ִ� ��带 �����Ѵ�.
*/

//************** update menu functions

void updateMenu();	
/*	function name : updateMenu()
	pre condition : nSelectedMainMenu�� ���� 3�̴�
	post condition : nUpdateMenu�� ���� 1 �Ǵ� 2�̴�.
	function : ��带 ������ �� �װ��� ������ ����� ���� �Լ��̴�. �����ͷ� ��带 ã�� �����ϰڴٰ� �ϸ� switch������ updateData()�� �����Ű�� ��ġ�� �����ϰڴٰ� �ϸ� updatePosition()�� �����Ų��
*/

void updateData();		
/*	function name : updateData()
	pre condition : nMenu�� ���� 1,2,3 �� �ϳ��̴�
	post condition : none
	function : �����ϰ� ���� �������� �������� �������� �Է��ϸ� �������� �����ִ� ��带 ã�� ���� �����Ѵ�
*/

void updatePosition();		

//************** retrieve menu functions

void retrieveMenu();	

//************** print menu functions

void printMenu();				
/*	function name : printList()
	pre condition : nSelectedMainMenu�� ���� 5�̴�
	post condition : nMenu�� ���� 1�Ǵ� 2�����Ѵ�.
	function : printMenu â�� ����� ������� �Է��� �޴´�.
*/

void printList(int option);		
/*	function name : printList(int option)
	pre condition : printList()���� nMenu�� ���� 1�̰ų� 2�̴�.
	post condition : none
	function : printMenu���� 1�� �������� SEQUENCE������� ����Ʈ�� ����ϰ�, 2�� �������� REVERSE������� ����Ѵ�.
*/
void recursiveList(ListNode * pVisited);

//************** init menu functions

void initFunc();		
/*	function name : initFunc()
	pre condition : nSelectedMainMenu�� ���� 6�̴�
	post condition : none
	function : ���� ���ϸ� �� �ָܼ޴����α׷��� �����ʱ�ȭ��Ű�� �Լ��̴�. ����ü�� �ִ� ��� ��带 �����ϰ�, �������� insertMenu()�� �ʱ⼳��ȭ������ �ٲ۴� 
	*/

//************** about menu functions

void about();				
/*	function name : about()
	pre condition : nSelectedMainMenu�� ���� 9�̴�
	post condition : none
	function : �� �ָܼ޴��� ���� ���, ���۱� � ���� �����Ѵ�.
	*/

//************** read/write menu functions

void readMenu();
void readTextFile();
void readBinaryFile();
int checkBeforeRead();

void writeMenu();
void writeTextFile();
void writeBinaryFile();



