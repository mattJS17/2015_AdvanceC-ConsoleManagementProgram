#include "consolemanagement.h" // consolemanagement.h인 헤터파일을 부른다.

int main()
{
	int nSelectedMainMenu;			// switch문에서 실행할 영역을 결정할 값을 저장한다
	int bIterationFlag = TRUE;		// while문을 무한루프로 만들고, bIterationFlag가 FALSE가 될때가 while문을 탈출한다

	pHeader = NULL;					// 포인터 값 초기화. 포인터가 아무것도 가르키고 있지 않다.
	g_nInsertType = NONE;			// 전역변수 초기화.

	while(bIterationFlag) {
		nSelectedMainMenu = displayMainMenu();		// displayMainMenu()를 통해 입력받은 값을 반환받아 nSelectedMainMenu에 저장한다.

		switch(nSelectedMainMenu) {

		case INSERT:
			if (g_nInsertType == NONE) insertMenu(); // 처음 실행 시켰을 때 위에서 값을 NONE이라고 했음으로 insertMenu(초기설정화면)가 나타남
			else if (g_nInsertType == ORDERED) insertToOrderedList(); // 초기설정화면에서 1을 눌러 Ordered list를 고르면 g_nInsertType이 ORDERED로 저장되 Management 메뉴창에서 INSERT를 고르면 항상 insertToOrderedList()가 호출된다.
			else if (g_nInsertType == UNORDERED) insertToUnorderedMenu(); // 초기설정화면에서 2을 눌러 Unordered list를 고르면 g_nInsertType이 UNORDERED로 저장되 Management 메뉴창에서 INSERT를 고르면 항상 insertToUnorderedList()가 호출된다.
			break;

		case REMOVE:
			removeMenu();			// displayMainMenu()에서 사용자가 2를 누르면 그 값이 반환되 removeMenu()가 실행된다
			break;

		case UPDATE:
			updateMenu();			// displayMainMenu()에서 사용자가 3를 누르면 그 값이 반환되 updateMenu()가 실행된다
			break;

		case RETRIEVE:
			retrieveMenu();			// displayMainMenu()에서 사용자가 4를 누르면 그 값이 반환되 retrieveMenu()가 실행된다
			break;

		case PRINT:
			printMenu();			// displayMainMenu()에서 사용자가 5를 누르면 그 값이 반환되 printMenu()가 실행된다
			break;	

		case INIT:
			initFunc();			// displayMainMenu()에서 사용자가 6를 누르면 그 값이 반환되 initFunc()가 실행된다
			break;	

		case READ:
			fflush(stdin);
			if (pHeader != NULL) {
				if (checkBeforeRead()) {
					writeMenu();
					system("pause");
				} // if

				initFunc();
				system("pause");
			} // if
			readMenu();		// displayMainMenu()에서 사용자가 7를 누르면 그 값이 반환되 readMenu()가 실행된다
			break;	

		case WRITE:
			writeMenu();		// displayMainMenu()에서 사용자가 8를 누르면 그 값이 반환되 writeMenu()가 실행된다
			break;	

		case ABOUT:
			about();			// displayMainMenu()에서 사용자가 9를 누르면 그 값이 반환되 about()가 실행된다
			break;	

		case EXIT:
			bIterationFlag = FALSE; // escape condition  while문의 조건인 bIteration의 값을 FALSE로 변경해 무한루프를 탈출한다.
			printf("\n\n\tGood-bye~\n");
			break;

		default:
			printf("\n\n\twrong number.. re-input\n"); //displayMainMenu()에서 1,2,3,4,5,0 외의 값이 반환되면 wrong number..re-input을 출력한다.

		} // switch	=> nSelectedMainMenu = displayMainMenu()에서 반환한 사용자가 선택한 메뉴번호이기 때문에 이 값에 맞는 case 영역을 실행한다.

		system("pause"); // switch문이 실행된 후 일시정지 상태로 만들어 다음 입력이 있을 때까지 멈춘다

	} /* while		 => switch문에 의해서 displayMainMenu()에서 사용자가 선택한 메뉴가 실행되도록 한다. 조건이 TRUE기 때문에 무한루프이고 
	  case EXIT에서 bIterationFlag = FALSE로 만들 때 무한루프를 탈출한다 
	  */

	return 0;
} // main()

int displayMainMenu()
{
	int nMenu;	// displayMainMenu에서 사용자가 입력하는 값을 저장한다

	system("cls"); // switch문 실행 뒤 Management 메뉴창으로 복귀할 때 이전 화면을 지운다
	printf("\n\n");
	printf("\t=====================================\n");
	printf("\t	MANAGEMENT MENU\n");
	printf("\t-------------------------------------\n");
	printf("\t	1. INSERT\n");
	printf("\t	2. REMOVE\n");
	printf("\t	3. UPDATE\n");
	printf("\t	4. RETRIEVE\n");
	printf("\t	5. PRINT\n");
	printf("\t	6. INIT\n");
	printf("\t	7. READ\n");
	printf("\t	8. WRITE\n");
	printf("\t	9. ABOUT\n");
	printf("\t-------------------------------------\n");
	printf("\t	0. EXIT\n");
	printf("\t=====================================\n");
	printf("\t	>> ");				// Management 메뉴창을 띄운다
	scanf("%d", &nMenu);		// 입력받은 값을 nMenu에 저장한다

	return nMenu;
} // displayMainMenu();		=> Management 메뉴창을 띄워주고 사용자가 번호를 누르면 그 값이 nMenu에 저장되고, 메인함수로 그 값을 반환시킨다

void insertMenu()		{
	int nInsertMenu; // ordered, unordered 값을 받기위한 변수.

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INSERT MENU\n");
	printf("\t------------------------------\n");
	printf("\t	1. Ordered List\n");
	printf("\t	2. Unordered List\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>>");					// insert Menu 창을 띄운다
	scanf("%d",&nInsertMenu);	// 입력받은 값은 nInsertMenu에 저장

	if (nInsertMenu == NONE) return;	// 0을 입력하면 main menu로 돌아간다

	g_nInsertType = nInsertMenu;		// 1 또는 2를 입력하면 다음에 insert menu를 누를 때 초기화면에서 결정한 방식으로만 값을 입력할 수 있다.
												// 초기화면에서 ORDERED를 정하면 계속 ORDERED가, UNORDERED를 고르면 계속 UNORDERED만 나오게 한다

	if (g_nInsertType == ORDERED) insertToOrderedList();	// 1을 눌러 ORDERED방식으로 insert하기 위해 insertToOrderList()를 실행시킨다
	else if (g_nInsertType == UNORDERED) insertToUnorderedMenu();	// 2을 눌러 UNORDERED방식으로 insert하기 위해 insertToUnorderList()를 실행시킨다
	
} //insertMenu()	

void insertToOrderedList()		{

	ListNode *pInput; //데이터를 입력받음
	ListNode *pVisited, *pPrev; //위치로 연결하기 위함 pVisited - 방문 포인터, pPrev - 백업 포인터

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INSERT Ordered List\n");
	printf("\t------------------------------\n");

	// input data, 노드 생성
	pInput = (ListNode *)malloc(sizeof(ListNode));
	printf("\tdata>> ");
	scanf("%d",&(pInput->data));
	pInput->link = NULL;		// 입력받은 data를 pInput->data에 저장하고 pInput->link는 아무것도 가르키지않게 NULL값으로 해서 pInput노드를 생성한다

	//linking
	if (pHeader == NULL) { // list is empty

		pHeader = pInput; // node made
								// pHeader==NULL일때 즉, 처음으로 값을 입력받을 때 pHeader를 pInput과 바로 연결 시킨다.
	} else {	// list is not empty

		pVisited = pHeader;
		pPrev = NULL;			// pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

		while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited가 앞에 있을 때 null을 가르켜 runtime 오류가 발생한다.(pVisited->data 성립 X). 해결방법1. 단축연산 이용-> &&일때 앞 조건이 false면 뒤에꺼 안봄(pVisited != NULL을 앞에 둔다)
			pPrev = pVisited;				// pPrev은 백업포인터로 pVisited가 전에 가르키던 값을 가르키고
			pVisited = pVisited->link;		// pVisited는 다음 노드로 이동한다.
			// if(pVisited == NULL) break;		해결방법2. (pVisited != NULL)을 조건에서 빼고 while문 안에 넣어 if(pVisited == NULL) break;가 while문의 조건보다 먼저 실행 되도록 한다.
		} // while		
		// ORDERED 방식은 큰 수가 앞으로 가기때문에 이 while문에서 pInput의 값을 기존 연결체의 노드값과 비교하면서 들어갈 곳을 찾는다.

		// insert  위의 while문에서 pInput이 들어갈 곳을 찾았으면 여기서 삽입한다.
		if (pPrev == NULL) {	// insert to the first node
			pInput->link = pHeader;
			pHeader = pInput;		// pHeader가 가르키는 첫번째 노드 앞에 pInput을 연결해 pInput을 첫번째 노드로 만든다
		} else {		// insert
			pInput->link = pPrev->link;
			pPrev->link= pInput;			// pInput을 삽입할 땐 pInput->link가 들어갈 곳의 다음 노드를 가리키고 전노드의 link가 pInput을 가르켜 연결체를 유지한다
		}

	} // if-else

} //insertToOrderList

void insertToUnorderedMenu()	{

	int nMenu;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t  INSERT Unordered Menu\n");
	printf("\t------------------------------\n");
	printf("\t	1. First Node\n");
	printf("\t	2. Random Node\n");
	printf("\t	3. Last Node\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>> ");				// Unordered Menu를 띄운다
	scanf("%d",&nMenu);		// 입력받은 값을 nMenu에 저장

	if (nMenu == PREVIOUS) return; // main menu로 돌아간다.

	if (nMenu>=FIRST_NODE && nMenu<=LAST_NODE) insertToUnorderedList(nMenu);		// nMenu의 값이 1,2,3일때만 insertToUnorderedList를 호출하겠다.		

	else {
		printf("\t	 WRONG INPUT  NUMBER!!\n");
	}

} // insertToUnorderedMenu

void insertToUnorderedList(int option)	{

	ListNode *pInput; //데이터를 입력받음
	ListNode *pVisited, *pPrev; //위치로 연결하기 위함 pVisited - 방문 포인터, pPrev - 백업 포인터

	int position, i;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INSERT Unordered List\n");;
	printf("\t------------------------------\n");

	pInput = (ListNode *)malloc(sizeof(ListNode));
	printf("\t data>> ");
	scanf("%d",&(pInput->data));
	pInput->link = NULL;					// 입력받은 data를 pInput->data에 저장하고 pInput->link는 아무것도 가르키지않게 NULL값으로 해서 pInput노드를 생성한다

	switch(option) { // Unordered Menu에서 입력받은 값에 의해 case가 실행된다.

	case FIRST_NODE:		// FIRST NODE는 값을 무조건 첫번째 노드에 저장한다. 따라서 pInput을 pHeader가 가르키는 값으로 만든다.

		pInput->link = pHeader;
		pHeader = pInput;			// pHeader가 가르키는 첫번째 노드 앞에 pInput을 연결해 pInput을 첫번째 노드로 만든다
		printf("\n\tInsert to the First Node\n");
		break;							

	case RANDOM_NODE:		// RANDOM NODE는 사용자가 원하는 위치에 값을 입력한다. 

		if (pHeader == NULL) {

			pHeader = pInput;
			printf("\n\t Empty List, insert to the first node\n");
							// pHeader가 NULL일때, 즉 노드가 없을때 pInput은 무조건 첫번째 값이 된다.
		} else {

			printf("\n\t position >> ");
			scanf("%d",&position);		// 사용자가 원하는 위치를 입력받는다.

			if (position<=0) {

				printf("\n\t position is %dth\n",position);
				printf("\t Invalid position!!\n");
										// 입력받은 position이 0보다 작을 때 position이 존재하지 않는다는 창을 띄운다
			} else if (position == 1) {  // insert to the first node 

				pInput->link = pHeader;
				pHeader = pInput;

				printf("\n\t Insert to the first node\n");
												// Position이 1일때 노드를 맨 앞에 넣는다
			} else {  // position >=2

				pVisited = pHeader;
				pPrev = NULL;       // pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

				for (i=1; i<position; i++) {
					pPrev = pVisited;
					pVisited = pVisited->link;

					if (pVisited == NULL) break; // 입력한 position으로 가는 도중 이미 연결체가 끝나면 for문을 빠져나온다.

				} // for		입력한 position으로 가기위해 옆노드로 계속 이동한다. 

				pInput->link=pPrev->link;
				pPrev->link=pInput;			// 입력한 position에 pInput을 넣는다. 

				if (pVisited == NULL) {
					printf("\n\t Invalied position, insert to the last node\n"); // position을 찾는 도중 연결체가 끝나면 연결체가 position보다 짧은 것임으로 마지막 노드에 삽입
				} else {
					printf("\n\t insert to the %dth position\n",position);
				}
			} // if - else

		} // if - else

		break;

	case LAST_NODE:				// LAST NODE는 값을 무조건 마지막 노드에 저장한다.
						
		if (pHeader == NULL) {

			pHeader = pInput;
										// pHeader가 NULL일때, 즉 노드가 없을때 pInput은 무조건 첫번째 값이 된다.
		} else {
			pVisited = pHeader;

			while (pVisited->link != NULL) { // pVisited->link != NULL임으로 빠져나왔을때 pVisited는 마지막노드를 가르킨다
				pVisited = pVisited->link;
			} // while   연결체의 마지막 노드로 이동한다.

			pInput->link = pVisited->link;
			pVisited->link = pInput;				// 마지막 노드의 다음노드로 pInput을 삽입한다.

		} // if - else

		printf("\n\t Insert to the last node\n");

		break;
	}

} // insertToUnorderedList

void removeMenu()	{

	int nRemoveMenu;

	system("cls");
	printf("\n\n");

	if (pHeader == NULL) {

		printf("\t  LIST is EMPTY!!\n");
		return;
							// 연결체가 존재하지 않으면 main Menu로 돌아간다.
	} // if

	printf("\t==============================\n");
	printf("\t	REMOVE MENU\n");
	printf("\t------------------------------\n");
	printf("\t	1. Data\n");
	printf("\t	2. Position\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>> ");						// remove Menu를 띄운다
	scanf("%d",&nRemoveMenu);	// 선택한 값을 nRemoveMenu에 저장한다

	switch(nRemoveMenu) {		// nRemoveMenu값으로 case 실행

	case DATA:
		removeData();			// removeMenu()에서 사용자가 1를 누르면  removeData()가 실행된다
		break;

	case POSITION:
		removePosition();		// removeMenu()에서 사용자가 2를 누르면  removeposition()가 실행된다
		break;

	case PREVIOUS: return;	// removeMenu()에서 사용자가 0를 누르면  main Menu로 돌아간다
	} // switch

} //removeMenu()

void removeData() {

	ListNode *pVisited, *pPrev;
	int nRemoveData;// pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL
	int check=0;			// 리스트에 nRemoveData가 존재하는지 하지않는지 체크하는 변수이다.

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	REMOVE DATA\n");
	printf("\t------------------------------\n");
	printf("\n");
	printf("\tdata>> ");			// remove data를 띄운다
	scanf("%d",&nRemoveData);	// 지우고 싶은 data를 입력받아 nRemoveData에 저장한다

	while(1) {

		if(pHeader == NULL) {
			break;					// pHeader가 NULL이면 break;
		}
		pVisited = pHeader;
		pPrev=NULL;			// pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL			

		while (pVisited->data != nRemoveData) {
			pPrev=pVisited;
			pVisited=pVisited->link;
			if (pVisited==NULL) break;		// 끝까지 갔는데 nRemoveData가 없으면 탈출.
		} // while          사용자가 입력한 nRemoveData가 리스트에 있는 확인하는 retrieve part

		if (pVisited == NULL) break;			// nRemoveData가 리스트에 없음으로 무한루프를 탈출한다.

		if (pPrev == NULL) {  // 첫번째 노드 삭제
			pHeader = pHeader->link;
			pVisited->link=NULL;
		} else {		// 첫번째가 아닌 노드 삭제
			pPrev->link=pVisited->link;
			pVisited->link = NULL;			// 내가 지우려는 위치의 전 노드를 내가 지우려는 노드의 다음 노드와 연결시키고 
													// 내가 지우려는 노드의 link를 NULL로 만들어 다음노드와의 연결을 끊는다. 따라서 pVisited가 가르키는 노드는 연결체에서 고립된다
		} // if-else

		free(pVisited);  // 노드를 삭제한다.
		check=1;			// 리스트에 nRemoveData가 존재하는지 하지않는지 체크하는 변수이다.
							// 리스트에 존재 하지않았다면 if (pVisited == NULL) break;가 실행됨으로 check값은 1로 변하지않는다.
	}
	if (check==1) printf("\n\t Data %d is removed!!\n",nRemoveData);		// check값이 1로 변하면 노드를 한개 이상 삭제했다는 뜻임으로 Data is removed 출력
	else printf("\n\t %d does not EXIST!!\n",nRemoveData);		// check값이 1로 변하지 않았다면 리스트에 nRemoveData가 존재하지 않음으로 does not EXIST 출력


} // removeData()

void removePosition() {
	ListNode *pVisited, *pPrev;
	int nRemovePosition,i;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	REMOVE POSITION\n");
	printf("\t------------------------------\n");
	printf("\n");
	printf("\tposition>> ");			// remove position를 띄운다
	scanf("%d",&nRemovePosition);	// 지우고 싶은 position를 입력받아 nRemovePosition에 저장한다

	pVisited = pHeader;
	pPrev = NULL;				// pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

	if (nRemovePosition<=0) {  // nRemovePosition가 0보다 작거나 같을 땐 범위에 없는 값이라고 하고 실행하지 않는다

		printf("\n\t position is %dth\n",nRemovePosition);
		printf("\t Invalid position!!\n");
								
	} else if (nRemovePosition == 1) {		// nRemovePosition가 1일 땐 첫번째 노드를 제거해 준다.

		pHeader=pHeader->link;
		free(pVisited);						// pHeader가 내가 지우려는 첫번째 노드가 아닌 그 다음 노드를 가르키게 하고 지운다.

		printf("\n\tRemoved position %d \n\n",nRemovePosition);

	} else {  // position >=2

		for (i=1; i<nRemovePosition; i++) {
			pPrev = pVisited;
			pVisited = pVisited->link;

			if (pVisited == NULL) break; // nRemovePosition가 리스트의 범위 내에 존재하지 않을 때 for문을 탈출한다.

		} // for			nRemovePosition의 위치로 이동하는 for문이다.

		if (pVisited == NULL) {  // nRemovePosition가 리스트의 범위 내에 존재하지 않음으로 Remove position %d does NOT exist라고 출력한다. 
			printf("\n\tRemove position %d does NOT exist!!\n",nRemovePosition);
		} else {
			pPrev->link = pVisited->link;

			pVisited->link = NULL;
												// 내가 지우려는 위치의 전 노드를 내가 지우려는 노드의 다음 노드와 연결시키고 
												// 내가 지우려는 노드의 link를 NULL로 만들어 다음노드와의 연결을 끊는다. 따라서 pVisited가 가르키는 노드는 연결체에서 고립된다
			printf("\n\tRemoved position %d \n\n",nRemovePosition);

			free(pVisited);
									// nRemovePosition이 리스트의 범위 내에 존재할 때 그 위치에 있는 노드를 제거한다. 
		} // if - else

	} // if - else

} // removePosition()

void updateMenu()		{

	int nUpdateMenu;

	system("cls");
	printf("\n\n");

	if (pHeader == NULL) {			// pHeader가 NULL일때 즉, 리스트가 존재 하지 않을때 실행한다.

		printf("\t  LIST is EMPTY!!\n");
		return;

	} // if				

	printf("\t==============================\n");
	printf("\t	UPDATE MENU\n");
	printf("\t------------------------------\n");
	printf("\t	1. Data\n");
	printf("\t	2. Position\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>> ");						// update menu를 창에 띄운다
	scanf("%d",&nUpdateMenu);		// update 시킬 방식을 골라 nUpdateMenu에 저장.

	switch(nUpdateMenu) {			// nUpdateMenu에 따라 case가 실행된다. 

	case DATA:
		updateData();				// UpdateMenu()에서 사용자가 1를 누르면 그 값이 반환되 updateData()가 실행된다
		break;

	case POSITION:
		updatePosition();			// UpdateMenu()에서 사용자가 2를 누르면 그 값이 반환되 updatePosition()가 실행된다
		break;

	case PREVIOUS: return;		// UpdateMenu()에서 사용자가 0을 누르면 메인메뉴로 돌아간다

	} // switch

}//updateMenu()	

void updateData()	{

	ListNode *pVisited, *pPrev;
	int nExistData, nUpdateData;
	ListNode *pInput;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	UPDATE DATA\n");
	printf("\t------------------------------\n");
	printf("\n");
	printf("\tExist data>> ");
	scanf("%d",&nExistData);
	printf("\tUpdate data>> ");
	scanf("%d",&nUpdateData);				
	// 존재하는 값과 변경할 값 2개를 입력받는다

	pVisited = pHeader;
	pPrev = NULL;					 // pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

	while (pVisited->data != nExistData) {

		pPrev = pVisited;
		pVisited = pVisited->link;
		if (pVisited == NULL) break; // 데이터가 연결리스트에 없을 때 while문 빠져나옴
	} // while  // 탈출 조건은 2개. 데이터가 리스트에 있을 때와 없을 때 

	// retrieve part


	// 데이터가 리스트에 없을 때
	if (pVisited == NULL) {	// remove data does not exist in the list

		printf("\n\t%d data does NOT exist!!\n",nExistData);
		return;
	} // if 


	//delete part, 데이터를 찾았을 때

	switch(g_nInsertType) {

	case ORDERED :	// ordered 방식은 내가 특정 노드를 지우고 다른 값을 입력하려고해도 ordered이기 때문에 재정렬된다. 따라서 그냥 remove와 insert를 같이 한다.

		// delete nExistData 
		if (pPrev == NULL)	pHeader = pHeader->link;			// pHeader가 내가 수정하려는 노드의 다음 노드를 가르킨다
		else					pPrev->link = pVisited->link;			// 내가 수정하려는 위치의 전 노드를 내가 수정하려는 노드의 다음 노드와 연결시키고 
													
		pVisited->link = NULL;		// 내가 수정하려는 노드의 link를 NULL로 만들어 다음노드와의 연결을 끊는다. 따라서 pVisited가 가르키는 노드는 연결체에서 고립된다
		free(pVisited);				// 수정할 노드를 삭제한다. 


		// insert nUpdateData

		pInput = (ListNode *)malloc(sizeof(ListNode));   // 동적할당 후 
		pInput->data=nUpdateData;							// 입력받은 값을 data field에 넣고
		pInput->link=NULL;									// link field에는 NULL을 넣어 아무것도 가르키지않게한다
		// 노드 생성

		if (pHeader == NULL) { // list is empty
			pHeader = pInput; // node made
		} // 노드 삭제 후 insert이기 때문에 노드가 1개 존재했다면 pHeader==NULL이 된다. 따라서 pHeader==NULL일때도 생각해야됨.

		else {

			pVisited = pHeader;
			pPrev = NULL;				 // pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

			while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited가 앞에 있을 때 null을 가르켜 runtime 오류가 발생한다.(pVisited->data 성립 X). 해결방법1. 단축연산 이용-> &&일때 앞 조건이 false면 뒤에꺼 안봄(pVisited != NULL을 앞에 둔다)
				pPrev = pVisited;
				pVisited = pVisited->link;
				// if(pVisited == NULL) break;		해결방법2. (pVisited != NULL)을 조건에서 빼고 while문 안에 넣어 if(pVisited == NULL) break;가 while문의 조건보다 먼저 실행 되도록 한다.
			} // while

			if (pPrev == NULL) {	// insert to the first node
				pInput->link = pHeader;
				pHeader = pInput;					// pHeader가 가르키는 첫번째 노드 앞에 pInput을 연결해 pInput을 첫번째 노드로 만든다
			} else {					// insert
				pInput->link = pPrev->link;					
				pPrev->link= pInput;				// pInput을 삽입할 땐 pInput->link가 들어갈 곳의 다음 노드를 가리키고 전노드의 link가 pInput을 가르켜 연결체를 유지한다
			}

		} // if-else

		printf("\tData Update : %d -> %d \n",nExistData, nUpdateData);
		break;

	case UNORDERED :			// unordered는 그냥 내가 수정할 곳의 위치를 위의 retrieve part에서 찾았기 때문에 그 곳의 데이터에 수정할 값을 넣으면 된다.

		pVisited->data = nUpdateData;
		printf("\tData Update : %d -> %d \n",nExistData, nUpdateData);

		break;
	} // switch

}

void updatePosition()	{

}

void retrieveMenu()	{

	int data;
	ListNode * pVisited;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	RETRIEVE MENU\n");
	printf("\t------------------------------\n");
	printf("\t>>");			
	scanf("%d",&data);


} //retrieveMenu()

void printMenu()		{

	int nMenu;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	PRINT	 MENU\n");
	printf("\t------------------------------\n");
	printf("\t	1. Sequence\n");
	printf("\t	2. Reverse\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>>");			// print menu를 창에 띄운다
	scanf("%d",&nMenu);	// 입력받은 값을 nMenu에 저장

	if (nMenu == PREVIOUS) return;	// 0을 입력하면 메인메뉴로 돌아간다

	if (nMenu == SEQUENCE || nMenu == REVERSE) printList(nMenu);		// 1이거나 2를 입력하면 printList(nMenu)를 실행한다.

	else {
		printf("\t	 WRONG INPUT  NUMBER!!\n");			// 그 외 번호를 입력하면 wrong input number!!를 띄우고 메인메뉴로 돌아간다
	}
} //printMenu()	

void printList(int option)	{

	ListNode * pVisited = pHeader; // 첫번째 노드를 가르킴

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	  LIST DATA\n");
	printf("\t------------------------------\n");

	if (pHeader == NULL) {  // pHeader가 NULL일때 즉 리스트에 노드가 존재 하지 않을때 EMPTY라고 띄운다

		printf("\t	  E M P T Y\n");
		printf("\t------------------------------\n");
	} else {
		switch(option) {   // printList()에서 nMenu의 값에 따라 case가 실행된다.

		case SEQUENCE:  // nMenu가 1일때 실행된다. 

			while(pVisited != NULL) { // pVisited가 NULL일때까지, 즉 마지막 노드일때까지 다음노드로 넘어가면서 노드의 값을 출력한다

				printf("\t	  %5d\n",pVisited->data);
				printf("\t------------------------------\n");
				pVisited = pVisited->link;			// 다음노드로 이동

			} // while
			printf("\t==============================\n");
			break;

		case REVERSE:

			recursiveList(pHeader);
			printf("\t==============================\n");
			break;

		} // switch
	} // else

} // printList()

void recursiveList(ListNode * pVisited) {
	
	// base case
	if (pVisited==NULL) return;

	// general case
	// smaller-caller
	else {

		recursiveList(pVisited->link);
		printf("\t	  %5d\n",pVisited->data);
		printf("\t------------------------------\n");
	
	}

} // recursiveList()

void initFunc() {    // 메인메뉴를 초기화한다 (공장초기화 느낌)

	ListNode *pVisited;
	char ch;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INIT MENU\n");
	printf("\t------------------------------\n");

	printf("\t init(y/n)? >> ");
	fflush(stdin);
	scanf("%c",&ch);  // 이닛을 진행할 것인가에 대한 사용자의 입력을 받는다.

	if (ch=='y' || ch=='Y') {
		while(pHeader !=NULL) {
			pVisited = pHeader;
			pHeader = pVisited->link;	// pHeader가 NULL을 가르킬때까지 계속 옆으로 이동하면서 pHeader가 다음노드로 이동하면 pVisited는 그 전노드를 가르켜
			free(pVisited);					// 그 전 노드를 삭제한다.
		} // while

		g_nInsertType=NONE;				// 공장초기화이기 때문에 한번 insert menu에서 ordered또는 unordered를 정하면 하나만 출력되는 것을 insert menu의 초기화면으로 바꾼다.
		printf("\t INIT LIST !!\n");

	} else {

		printf("\t CANCEL..\n");
	} // if-else

} // initFunc()

void about() {

	system("cls");
	printf("\n\n");

	printf("\t===================================\n");
	printf("\t Management Program ver 0.8\n");
	printf("\n");
	printf("\t Programmed by Shim, JaeHoon\n");
	printf("\t 15010979, Computer Enginnering\n");
	printf("\n");
	printf("\t Copyright@ M.J.Shim\n");
	printf("\t-----------------------------------\n");
					// about()는 말그대로 이 콘솔프로그램에 대해 설명하는 함수이다. 무슨 버전인지, 누가 만들었는지, 누구의 저작권인지 등을 표시한다. 
}

void readMenu() {
	int nReadMenu;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	Read from file\n");
	printf("\t------------------------------\n");
	printf("\t	1. Text mode\n");
	printf("\t	2. Binary mode\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>>");			
	scanf("%d",&nReadMenu);	

	if (nReadMenu == PREVIOUS) return;

	switch(nReadMenu) {

	case TEXT:
		readTextFile();
		break;

	case BINARY:
		readBinaryFile();
		break;
	} // switch

} // readMenu()

void readTextFile() {

	FILE * fpIn;
	char strFileName[40];
	ListNode * pInput, *pVisited, *pPrev;

	system("cls");
	printf("\n\n");

	printf("\t==============================\n");
	printf("\t	Read from the text file\n");
	printf("\t------------------------------\n");
	printf("\t	1. Ordered\n");
	printf("\t	2. Unordered\n");
	printf("\t------------------------------\n");
	printf("\t>> ");			
	scanf("%d",&g_nInsertType);

	printf("\n");
	printf("\tinput file name >> ");
	scanf("%s",strFileName);

	fpIn = fopen(strFileName,"r");
	if (fpIn == NULL) {
		printf("\tCan't open the file, %s\n",strFileName);
		return;
	} // if
	printf("\tSuccess %s file open\n",strFileName);

	while(TRUE) {
		pInput = (ListNode *)malloc(sizeof(ListNode));
		if (fscanf(fpIn, "%d", &(pInput->data)) == EOF) break;
		pInput->link = NULL;	

		switch(g_nInsertType) {

		case ORDERED:

			if (pHeader == NULL) pHeader = pInput;
			else {

				pVisited = pHeader;
				pPrev = NULL;			// pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

				while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited가 앞에 있을 때 null을 가르켜 runtime 오류가 발생한다.(pVisited->data 성립 X). 해결방법1. 단축연산 이용-> &&일때 앞 조건이 false면 뒤에꺼 안봄(pVisited != NULL을 앞에 둔다)
					pPrev = pVisited;				// pPrev은 백업포인터로 pVisited가 전에 가르키던 값을 가르키고
					pVisited = pVisited->link;		// pVisited는 다음 노드로 이동한다.
					// if(pVisited == NULL) break;		해결방법2. (pVisited != NULL)을 조건에서 빼고 while문 안에 넣어 if(pVisited == NULL) break;가 while문의 조건보다 먼저 실행 되도록 한다.
				} 
				if (pPrev == NULL) {	// insert to the first node
					pInput->link = pHeader;
					pHeader = pInput;		// pHeader가 가르키는 첫번째 노드 앞에 pInput을 연결해 pInput을 첫번째 노드로 만든다
				} else {		// insert
					pInput->link = pPrev->link;
					pPrev->link= pInput;			// pInput을 삽입할 땐 pInput->link가 들어갈 곳의 다음 노드를 가리키고 전노드의 link가 pInput을 가르켜 연결체를 유지한다
				}

			} // else
			break;

		case UNORDERED:

			pInput->link = pHeader;
			pHeader = pInput;

			break;
		} // switch
	} // while
	printf("\n");
	printf("\tInsert to the LIST from file data\n");
	printf("\n");

	fclose(fpIn);

} // readTextFile()

void readBinaryFile() {

	FILE * fpIn;
	char strFileName[40];
	int i, nNodeCount=0,nEOF=0;
	ListNode * pInput, *pVisited, *pPrev;

	system("cls");
	printf("\n\n");

	printf("\t==============================\n");
	printf("\t	Read from the binary file\n");
	printf("\t------------------------------\n");
	printf("\t	1. Ordered\n");
	printf("\t	2. Unordered\n");
	printf("\t------------------------------\n");
	printf("\t	>> ");			
	scanf("%d",&g_nInsertType);

	printf("\n");
	printf("\tinput(binary) file name >>");
	scanf("%s",strFileName);

	fpIn = fopen(strFileName,"rb");
	if (fpIn == NULL) {
		printf("\tCan't open the input file, %s\n",strFileName);
	} //if

	fseek(fpIn,0,SEEK_END);
	nEOF = ftell(fpIn);
	nNodeCount = nEOF/sizeof(ListNode);

	fseek(fpIn,0,SEEK_SET); // == rewind(fpIn);

	for (i=0; i<nNodeCount; i++) {

		pInput = (ListNode *)malloc(sizeof(ListNode));
		fread(pInput,sizeof(ListNode),1,fpIn);
		pInput->link = NULL;

		switch(g_nInsertType) {

		case ORDERED:

			if (pHeader == NULL) pHeader = pInput;
			else {

				pVisited = pHeader;
				pPrev = NULL;			// pVisited는 pHeader와 같은 곳을 가르키고 pPrev은 NULL

				while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited가 앞에 있을 때 null을 가르켜 runtime 오류가 발생한다.(pVisited->data 성립 X). 해결방법1. 단축연산 이용-> &&일때 앞 조건이 false면 뒤에꺼 안봄(pVisited != NULL을 앞에 둔다)
					pPrev = pVisited;				// pPrev은 백업포인터로 pVisited가 전에 가르키던 값을 가르키고
					pVisited = pVisited->link;		// pVisited는 다음 노드로 이동한다.
					// if(pVisited == NULL) break;		해결방법2. (pVisited != NULL)을 조건에서 빼고 while문 안에 넣어 if(pVisited == NULL) break;가 while문의 조건보다 먼저 실행 되도록 한다.
				} 
				if (pPrev == NULL) {	// insert to the first node
					pInput->link = pHeader;
					pHeader = pInput;		// pHeader가 가르키는 첫번째 노드 앞에 pInput을 연결해 pInput을 첫번째 노드로 만든다
				} else {		// insert
					pInput->link = pPrev->link;
					pPrev->link= pInput;			// pInput을 삽입할 땐 pInput->link가 들어갈 곳의 다음 노드를 가리키고 전노드의 link가 pInput을 가르켜 연결체를 유지한다
				}

			} // else
			break;

		case UNORDERED:

			pInput->link = pHeader;
			pHeader = pInput;

			break;
		} // switch

	} // for

	fclose(fpIn);

} // readBinaryFile()

void writeMenu() {

	int nWriteMenu;

	system("cls");
	printf("\n\n");

	if (pHeader==NULL) {
		printf("\tLIST is EMPTY!!\n\n");
		return;
	} // if

	printf("\t==============================\n");
	printf("\t	Write to a file\n");
	printf("\t------------------------------\n");
	printf("\t	1. Text mode\n");
	printf("\t	2. Binary mode\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>> ");			
	scanf("%d",&nWriteMenu);

	if (nWriteMenu == PREVIOUS) return;

	switch(nWriteMenu) {

	case TEXT:
		writeTextFile();
		break;

	case BINARY:
		writeBinaryFile();
		break;

	} // switch

} // writeMenu()

void writeTextFile() {

	FILE *fpOut;
	int nWriteMode, i;
	char strFileName[40];
	ListNode * pVisited;

	system("cls");
	printf("\n\n");

	printf("\t==============================\n");
	printf("\t	Write to the text file\n");
	printf("\t------------------------------\n");
	printf("\t	1. Data Only\n");
	printf("\t	2. Output format\n");
	printf("\t------------------------------\n");
	printf("\t>> ");			
	scanf("%d",&nWriteMode);

	printf("\n");
	printf("\tOutput File Name >> ");
	scanf("%s", strFileName);

	for (i=0; i<strlen(strFileName); i++) {
		if (strFileName[i] == '.') break;
	} // for
	strFileName[i]='\0';

	switch(nWriteMode) {

	case DATA_ONLY:
		strcat(strFileName,"(data_only).txt");

		break;

	case OUTPUT_FORMAT:
		strcat(strFileName,"(output_only).txt");
		break;

	} // switch

	printf("\n");
	printf("\trenamed the outpur file, %s\n\n",strFileName);

	fpOut = fopen(strFileName,"w");
	if (fpOut == NULL) {
		printf("\n");
		printf("\tCan't open the output file, %s",strFileName);
		return;
	} // if

	if (nWriteMode == OUTPUT_FORMAT) {
		fprintf(fpOut,"======\n");
		fprintf(fpOut," DATA\n");
		fprintf(fpOut,"---------\n");
	} // if

	// data
	pVisited = pHeader;
	while(pVisited != NULL) {
		fprintf(fpOut,"%d\n",pVisited->data);
		pVisited = pVisited->link;
	} // while

	if (nWriteMode == OUTPUT_FORMAT) {
		fprintf(fpOut,"======\n");
	} // if

	printf("\n");
	printf("\tSuccess write to the output file, %s\n\n",strFileName);

	fclose(fpOut);

} // writeTextFile()

void writeBinaryFile() {

	FILE * fpOut;
	char strFileName[40];
	ListNode *pVisited;


	system("cls");
	printf("\n\n");

	printf("\t==============================\n");
	printf("\t	Write to the binary file\n");
	printf("\t------------------------------\n");
	printf("\n");
	printf("\t	Output(binary) file name >> ");
	scanf("%s",strFileName);

	fpOut = fopen(strFileName,"wb");
	if (fpOut == NULL) {
		printf("\t	Can't open the output file, %s\n",strFileName);
		return;
	} // if

	pVisited = pHeader;
	while(pVisited != NULL) {

		fwrite(pVisited,sizeof(ListNode),1,fpOut);  // data + link
//		fwrite(&(pVisited->data),sizeof(pVisited->data),1,fpOut); // data
		pVisited=pVisited->link;
	} // while

	printf("\t	Success write to the binary file, %s\n",strFileName);

	fclose(fpOut);

}

int checkBeforeRead() {

	char chSaved;

	printf("\n");
	printf("\tData exist in list\n");
	printf("\tSave (y/n) ? ");
	scanf("%c", &chSaved);

	if (chSaved == 'y')	return TRUE;
	else					return FALSE;

} // checkBeforeRead()