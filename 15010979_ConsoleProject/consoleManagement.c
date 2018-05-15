#include "consolemanagement.h" // consolemanagement.h�� ���������� �θ���.

int main()
{
	int nSelectedMainMenu;			// switch������ ������ ������ ������ ���� �����Ѵ�
	int bIterationFlag = TRUE;		// while���� ���ѷ����� �����, bIterationFlag�� FALSE�� �ɶ��� while���� Ż���Ѵ�

	pHeader = NULL;					// ������ �� �ʱ�ȭ. �����Ͱ� �ƹ��͵� ����Ű�� ���� �ʴ�.
	g_nInsertType = NONE;			// �������� �ʱ�ȭ.

	while(bIterationFlag) {
		nSelectedMainMenu = displayMainMenu();		// displayMainMenu()�� ���� �Է¹��� ���� ��ȯ�޾� nSelectedMainMenu�� �����Ѵ�.

		switch(nSelectedMainMenu) {

		case INSERT:
			if (g_nInsertType == NONE) insertMenu(); // ó�� ���� ������ �� ������ ���� NONE�̶�� �������� insertMenu(�ʱ⼳��ȭ��)�� ��Ÿ��
			else if (g_nInsertType == ORDERED) insertToOrderedList(); // �ʱ⼳��ȭ�鿡�� 1�� ���� Ordered list�� ���� g_nInsertType�� ORDERED�� ����� Management �޴�â���� INSERT�� ���� �׻� insertToOrderedList()�� ȣ��ȴ�.
			else if (g_nInsertType == UNORDERED) insertToUnorderedMenu(); // �ʱ⼳��ȭ�鿡�� 2�� ���� Unordered list�� ���� g_nInsertType�� UNORDERED�� ����� Management �޴�â���� INSERT�� ���� �׻� insertToUnorderedList()�� ȣ��ȴ�.
			break;

		case REMOVE:
			removeMenu();			// displayMainMenu()���� ����ڰ� 2�� ������ �� ���� ��ȯ�� removeMenu()�� ����ȴ�
			break;

		case UPDATE:
			updateMenu();			// displayMainMenu()���� ����ڰ� 3�� ������ �� ���� ��ȯ�� updateMenu()�� ����ȴ�
			break;

		case RETRIEVE:
			retrieveMenu();			// displayMainMenu()���� ����ڰ� 4�� ������ �� ���� ��ȯ�� retrieveMenu()�� ����ȴ�
			break;

		case PRINT:
			printMenu();			// displayMainMenu()���� ����ڰ� 5�� ������ �� ���� ��ȯ�� printMenu()�� ����ȴ�
			break;	

		case INIT:
			initFunc();			// displayMainMenu()���� ����ڰ� 6�� ������ �� ���� ��ȯ�� initFunc()�� ����ȴ�
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
			readMenu();		// displayMainMenu()���� ����ڰ� 7�� ������ �� ���� ��ȯ�� readMenu()�� ����ȴ�
			break;	

		case WRITE:
			writeMenu();		// displayMainMenu()���� ����ڰ� 8�� ������ �� ���� ��ȯ�� writeMenu()�� ����ȴ�
			break;	

		case ABOUT:
			about();			// displayMainMenu()���� ����ڰ� 9�� ������ �� ���� ��ȯ�� about()�� ����ȴ�
			break;	

		case EXIT:
			bIterationFlag = FALSE; // escape condition  while���� ������ bIteration�� ���� FALSE�� ������ ���ѷ����� Ż���Ѵ�.
			printf("\n\n\tGood-bye~\n");
			break;

		default:
			printf("\n\n\twrong number.. re-input\n"); //displayMainMenu()���� 1,2,3,4,5,0 ���� ���� ��ȯ�Ǹ� wrong number..re-input�� ����Ѵ�.

		} // switch	=> nSelectedMainMenu = displayMainMenu()���� ��ȯ�� ����ڰ� ������ �޴���ȣ�̱� ������ �� ���� �´� case ������ �����Ѵ�.

		system("pause"); // switch���� ����� �� �Ͻ����� ���·� ����� ���� �Է��� ���� ������ �����

	} /* while		 => switch���� ���ؼ� displayMainMenu()���� ����ڰ� ������ �޴��� ����ǵ��� �Ѵ�. ������ TRUE�� ������ ���ѷ����̰� 
	  case EXIT���� bIterationFlag = FALSE�� ���� �� ���ѷ����� Ż���Ѵ� 
	  */

	return 0;
} // main()

int displayMainMenu()
{
	int nMenu;	// displayMainMenu���� ����ڰ� �Է��ϴ� ���� �����Ѵ�

	system("cls"); // switch�� ���� �� Management �޴�â���� ������ �� ���� ȭ���� �����
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
	printf("\t	>> ");				// Management �޴�â�� ����
	scanf("%d", &nMenu);		// �Է¹��� ���� nMenu�� �����Ѵ�

	return nMenu;
} // displayMainMenu();		=> Management �޴�â�� ����ְ� ����ڰ� ��ȣ�� ������ �� ���� nMenu�� ����ǰ�, �����Լ��� �� ���� ��ȯ��Ų��

void insertMenu()		{
	int nInsertMenu; // ordered, unordered ���� �ޱ����� ����.

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
	printf("\t>>");					// insert Menu â�� ����
	scanf("%d",&nInsertMenu);	// �Է¹��� ���� nInsertMenu�� ����

	if (nInsertMenu == NONE) return;	// 0�� �Է��ϸ� main menu�� ���ư���

	g_nInsertType = nInsertMenu;		// 1 �Ǵ� 2�� �Է��ϸ� ������ insert menu�� ���� �� �ʱ�ȭ�鿡�� ������ ������θ� ���� �Է��� �� �ִ�.
												// �ʱ�ȭ�鿡�� ORDERED�� ���ϸ� ��� ORDERED��, UNORDERED�� ���� ��� UNORDERED�� ������ �Ѵ�

	if (g_nInsertType == ORDERED) insertToOrderedList();	// 1�� ���� ORDERED������� insert�ϱ� ���� insertToOrderList()�� �����Ų��
	else if (g_nInsertType == UNORDERED) insertToUnorderedMenu();	// 2�� ���� UNORDERED������� insert�ϱ� ���� insertToUnorderList()�� �����Ų��
	
} //insertMenu()	

void insertToOrderedList()		{

	ListNode *pInput; //�����͸� �Է¹���
	ListNode *pVisited, *pPrev; //��ġ�� �����ϱ� ���� pVisited - �湮 ������, pPrev - ��� ������

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INSERT Ordered List\n");
	printf("\t------------------------------\n");

	// input data, ��� ����
	pInput = (ListNode *)malloc(sizeof(ListNode));
	printf("\tdata>> ");
	scanf("%d",&(pInput->data));
	pInput->link = NULL;		// �Է¹��� data�� pInput->data�� �����ϰ� pInput->link�� �ƹ��͵� ����Ű���ʰ� NULL������ �ؼ� pInput��带 �����Ѵ�

	//linking
	if (pHeader == NULL) { // list is empty

		pHeader = pInput; // node made
								// pHeader==NULL�϶� ��, ó������ ���� �Է¹��� �� pHeader�� pInput�� �ٷ� ���� ��Ų��.
	} else {	// list is not empty

		pVisited = pHeader;
		pPrev = NULL;			// pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

		while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited�� �տ� ���� �� null�� ������ runtime ������ �߻��Ѵ�.(pVisited->data ���� X). �ذ���1. ���࿬�� �̿�-> &&�϶� �� ������ false�� �ڿ��� �Ⱥ�(pVisited != NULL�� �տ� �д�)
			pPrev = pVisited;				// pPrev�� ��������ͷ� pVisited�� ���� ����Ű�� ���� ����Ű��
			pVisited = pVisited->link;		// pVisited�� ���� ���� �̵��Ѵ�.
			// if(pVisited == NULL) break;		�ذ���2. (pVisited != NULL)�� ���ǿ��� ���� while�� �ȿ� �־� if(pVisited == NULL) break;�� while���� ���Ǻ��� ���� ���� �ǵ��� �Ѵ�.
		} // while		
		// ORDERED ����� ū ���� ������ ���⶧���� �� while������ pInput�� ���� ���� ����ü�� ��尪�� ���ϸ鼭 �� ���� ã�´�.

		// insert  ���� while������ pInput�� �� ���� ã������ ���⼭ �����Ѵ�.
		if (pPrev == NULL) {	// insert to the first node
			pInput->link = pHeader;
			pHeader = pInput;		// pHeader�� ����Ű�� ù��° ��� �տ� pInput�� ������ pInput�� ù��° ���� �����
		} else {		// insert
			pInput->link = pPrev->link;
			pPrev->link= pInput;			// pInput�� ������ �� pInput->link�� �� ���� ���� ��带 ����Ű�� ������� link�� pInput�� ������ ����ü�� �����Ѵ�
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
	printf("\t>> ");				// Unordered Menu�� ����
	scanf("%d",&nMenu);		// �Է¹��� ���� nMenu�� ����

	if (nMenu == PREVIOUS) return; // main menu�� ���ư���.

	if (nMenu>=FIRST_NODE && nMenu<=LAST_NODE) insertToUnorderedList(nMenu);		// nMenu�� ���� 1,2,3�϶��� insertToUnorderedList�� ȣ���ϰڴ�.		

	else {
		printf("\t	 WRONG INPUT  NUMBER!!\n");
	}

} // insertToUnorderedMenu

void insertToUnorderedList(int option)	{

	ListNode *pInput; //�����͸� �Է¹���
	ListNode *pVisited, *pPrev; //��ġ�� �����ϱ� ���� pVisited - �湮 ������, pPrev - ��� ������

	int position, i;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INSERT Unordered List\n");;
	printf("\t------------------------------\n");

	pInput = (ListNode *)malloc(sizeof(ListNode));
	printf("\t data>> ");
	scanf("%d",&(pInput->data));
	pInput->link = NULL;					// �Է¹��� data�� pInput->data�� �����ϰ� pInput->link�� �ƹ��͵� ����Ű���ʰ� NULL������ �ؼ� pInput��带 �����Ѵ�

	switch(option) { // Unordered Menu���� �Է¹��� ���� ���� case�� ����ȴ�.

	case FIRST_NODE:		// FIRST NODE�� ���� ������ ù��° ��忡 �����Ѵ�. ���� pInput�� pHeader�� ����Ű�� ������ �����.

		pInput->link = pHeader;
		pHeader = pInput;			// pHeader�� ����Ű�� ù��° ��� �տ� pInput�� ������ pInput�� ù��° ���� �����
		printf("\n\tInsert to the First Node\n");
		break;							

	case RANDOM_NODE:		// RANDOM NODE�� ����ڰ� ���ϴ� ��ġ�� ���� �Է��Ѵ�. 

		if (pHeader == NULL) {

			pHeader = pInput;
			printf("\n\t Empty List, insert to the first node\n");
							// pHeader�� NULL�϶�, �� ��尡 ������ pInput�� ������ ù��° ���� �ȴ�.
		} else {

			printf("\n\t position >> ");
			scanf("%d",&position);		// ����ڰ� ���ϴ� ��ġ�� �Է¹޴´�.

			if (position<=0) {

				printf("\n\t position is %dth\n",position);
				printf("\t Invalid position!!\n");
										// �Է¹��� position�� 0���� ���� �� position�� �������� �ʴ´ٴ� â�� ����
			} else if (position == 1) {  // insert to the first node 

				pInput->link = pHeader;
				pHeader = pInput;

				printf("\n\t Insert to the first node\n");
												// Position�� 1�϶� ��带 �� �տ� �ִ´�
			} else {  // position >=2

				pVisited = pHeader;
				pPrev = NULL;       // pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

				for (i=1; i<position; i++) {
					pPrev = pVisited;
					pVisited = pVisited->link;

					if (pVisited == NULL) break; // �Է��� position���� ���� ���� �̹� ����ü�� ������ for���� �������´�.

				} // for		�Է��� position���� �������� ������ ��� �̵��Ѵ�. 

				pInput->link=pPrev->link;
				pPrev->link=pInput;			// �Է��� position�� pInput�� �ִ´�. 

				if (pVisited == NULL) {
					printf("\n\t Invalied position, insert to the last node\n"); // position�� ã�� ���� ����ü�� ������ ����ü�� position���� ª�� �������� ������ ��忡 ����
				} else {
					printf("\n\t insert to the %dth position\n",position);
				}
			} // if - else

		} // if - else

		break;

	case LAST_NODE:				// LAST NODE�� ���� ������ ������ ��忡 �����Ѵ�.
						
		if (pHeader == NULL) {

			pHeader = pInput;
										// pHeader�� NULL�϶�, �� ��尡 ������ pInput�� ������ ù��° ���� �ȴ�.
		} else {
			pVisited = pHeader;

			while (pVisited->link != NULL) { // pVisited->link != NULL������ ������������ pVisited�� ��������带 ����Ų��
				pVisited = pVisited->link;
			} // while   ����ü�� ������ ���� �̵��Ѵ�.

			pInput->link = pVisited->link;
			pVisited->link = pInput;				// ������ ����� �������� pInput�� �����Ѵ�.

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
							// ����ü�� �������� ������ main Menu�� ���ư���.
	} // if

	printf("\t==============================\n");
	printf("\t	REMOVE MENU\n");
	printf("\t------------------------------\n");
	printf("\t	1. Data\n");
	printf("\t	2. Position\n");
	printf("\t------------------------------\n");
	printf("\t	0. Previous\n");
	printf("\t==============================\n");
	printf("\t>> ");						// remove Menu�� ����
	scanf("%d",&nRemoveMenu);	// ������ ���� nRemoveMenu�� �����Ѵ�

	switch(nRemoveMenu) {		// nRemoveMenu������ case ����

	case DATA:
		removeData();			// removeMenu()���� ����ڰ� 1�� ������  removeData()�� ����ȴ�
		break;

	case POSITION:
		removePosition();		// removeMenu()���� ����ڰ� 2�� ������  removeposition()�� ����ȴ�
		break;

	case PREVIOUS: return;	// removeMenu()���� ����ڰ� 0�� ������  main Menu�� ���ư���
	} // switch

} //removeMenu()

void removeData() {

	ListNode *pVisited, *pPrev;
	int nRemoveData;// pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL
	int check=0;			// ����Ʈ�� nRemoveData�� �����ϴ��� �����ʴ��� üũ�ϴ� �����̴�.

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	REMOVE DATA\n");
	printf("\t------------------------------\n");
	printf("\n");
	printf("\tdata>> ");			// remove data�� ����
	scanf("%d",&nRemoveData);	// ����� ���� data�� �Է¹޾� nRemoveData�� �����Ѵ�

	while(1) {

		if(pHeader == NULL) {
			break;					// pHeader�� NULL�̸� break;
		}
		pVisited = pHeader;
		pPrev=NULL;			// pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL			

		while (pVisited->data != nRemoveData) {
			pPrev=pVisited;
			pVisited=pVisited->link;
			if (pVisited==NULL) break;		// ������ ���µ� nRemoveData�� ������ Ż��.
		} // while          ����ڰ� �Է��� nRemoveData�� ����Ʈ�� �ִ� Ȯ���ϴ� retrieve part

		if (pVisited == NULL) break;			// nRemoveData�� ����Ʈ�� �������� ���ѷ����� Ż���Ѵ�.

		if (pPrev == NULL) {  // ù��° ��� ����
			pHeader = pHeader->link;
			pVisited->link=NULL;
		} else {		// ù��°�� �ƴ� ��� ����
			pPrev->link=pVisited->link;
			pVisited->link = NULL;			// ���� ������� ��ġ�� �� ��带 ���� ������� ����� ���� ���� �����Ű�� 
													// ���� ������� ����� link�� NULL�� ����� ���������� ������ ���´�. ���� pVisited�� ����Ű�� ���� ����ü���� ���ȴ�
		} // if-else

		free(pVisited);  // ��带 �����Ѵ�.
		check=1;			// ����Ʈ�� nRemoveData�� �����ϴ��� �����ʴ��� üũ�ϴ� �����̴�.
							// ����Ʈ�� ���� �����ʾҴٸ� if (pVisited == NULL) break;�� ��������� check���� 1�� �������ʴ´�.
	}
	if (check==1) printf("\n\t Data %d is removed!!\n",nRemoveData);		// check���� 1�� ���ϸ� ��带 �Ѱ� �̻� �����ߴٴ� �������� Data is removed ���
	else printf("\n\t %d does not EXIST!!\n",nRemoveData);		// check���� 1�� ������ �ʾҴٸ� ����Ʈ�� nRemoveData�� �������� �������� does not EXIST ���


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
	printf("\tposition>> ");			// remove position�� ����
	scanf("%d",&nRemovePosition);	// ����� ���� position�� �Է¹޾� nRemovePosition�� �����Ѵ�

	pVisited = pHeader;
	pPrev = NULL;				// pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

	if (nRemovePosition<=0) {  // nRemovePosition�� 0���� �۰ų� ���� �� ������ ���� ���̶�� �ϰ� �������� �ʴ´�

		printf("\n\t position is %dth\n",nRemovePosition);
		printf("\t Invalid position!!\n");
								
	} else if (nRemovePosition == 1) {		// nRemovePosition�� 1�� �� ù��° ��带 ������ �ش�.

		pHeader=pHeader->link;
		free(pVisited);						// pHeader�� ���� ������� ù��° ��尡 �ƴ� �� ���� ��带 ����Ű�� �ϰ� �����.

		printf("\n\tRemoved position %d \n\n",nRemovePosition);

	} else {  // position >=2

		for (i=1; i<nRemovePosition; i++) {
			pPrev = pVisited;
			pVisited = pVisited->link;

			if (pVisited == NULL) break; // nRemovePosition�� ����Ʈ�� ���� ���� �������� ���� �� for���� Ż���Ѵ�.

		} // for			nRemovePosition�� ��ġ�� �̵��ϴ� for���̴�.

		if (pVisited == NULL) {  // nRemovePosition�� ����Ʈ�� ���� ���� �������� �������� Remove position %d does NOT exist��� ����Ѵ�. 
			printf("\n\tRemove position %d does NOT exist!!\n",nRemovePosition);
		} else {
			pPrev->link = pVisited->link;

			pVisited->link = NULL;
												// ���� ������� ��ġ�� �� ��带 ���� ������� ����� ���� ���� �����Ű�� 
												// ���� ������� ����� link�� NULL�� ����� ���������� ������ ���´�. ���� pVisited�� ����Ű�� ���� ����ü���� ���ȴ�
			printf("\n\tRemoved position %d \n\n",nRemovePosition);

			free(pVisited);
									// nRemovePosition�� ����Ʈ�� ���� ���� ������ �� �� ��ġ�� �ִ� ��带 �����Ѵ�. 
		} // if - else

	} // if - else

} // removePosition()

void updateMenu()		{

	int nUpdateMenu;

	system("cls");
	printf("\n\n");

	if (pHeader == NULL) {			// pHeader�� NULL�϶� ��, ����Ʈ�� ���� ���� ������ �����Ѵ�.

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
	printf("\t>> ");						// update menu�� â�� ����
	scanf("%d",&nUpdateMenu);		// update ��ų ����� ��� nUpdateMenu�� ����.

	switch(nUpdateMenu) {			// nUpdateMenu�� ���� case�� ����ȴ�. 

	case DATA:
		updateData();				// UpdateMenu()���� ����ڰ� 1�� ������ �� ���� ��ȯ�� updateData()�� ����ȴ�
		break;

	case POSITION:
		updatePosition();			// UpdateMenu()���� ����ڰ� 2�� ������ �� ���� ��ȯ�� updatePosition()�� ����ȴ�
		break;

	case PREVIOUS: return;		// UpdateMenu()���� ����ڰ� 0�� ������ ���θ޴��� ���ư���

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
	// �����ϴ� ���� ������ �� 2���� �Է¹޴´�

	pVisited = pHeader;
	pPrev = NULL;					 // pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

	while (pVisited->data != nExistData) {

		pPrev = pVisited;
		pVisited = pVisited->link;
		if (pVisited == NULL) break; // �����Ͱ� ���Ḯ��Ʈ�� ���� �� while�� ��������
	} // while  // Ż�� ������ 2��. �����Ͱ� ����Ʈ�� ���� ���� ���� �� 

	// retrieve part


	// �����Ͱ� ����Ʈ�� ���� ��
	if (pVisited == NULL) {	// remove data does not exist in the list

		printf("\n\t%d data does NOT exist!!\n",nExistData);
		return;
	} // if 


	//delete part, �����͸� ã���� ��

	switch(g_nInsertType) {

	case ORDERED :	// ordered ����� ���� Ư�� ��带 ����� �ٸ� ���� �Է��Ϸ����ص� ordered�̱� ������ �����ĵȴ�. ���� �׳� remove�� insert�� ���� �Ѵ�.

		// delete nExistData 
		if (pPrev == NULL)	pHeader = pHeader->link;			// pHeader�� ���� �����Ϸ��� ����� ���� ��带 ����Ų��
		else					pPrev->link = pVisited->link;			// ���� �����Ϸ��� ��ġ�� �� ��带 ���� �����Ϸ��� ����� ���� ���� �����Ű�� 
													
		pVisited->link = NULL;		// ���� �����Ϸ��� ����� link�� NULL�� ����� ���������� ������ ���´�. ���� pVisited�� ����Ű�� ���� ����ü���� ���ȴ�
		free(pVisited);				// ������ ��带 �����Ѵ�. 


		// insert nUpdateData

		pInput = (ListNode *)malloc(sizeof(ListNode));   // �����Ҵ� �� 
		pInput->data=nUpdateData;							// �Է¹��� ���� data field�� �ְ�
		pInput->link=NULL;									// link field���� NULL�� �־� �ƹ��͵� ����Ű���ʰ��Ѵ�
		// ��� ����

		if (pHeader == NULL) { // list is empty
			pHeader = pInput; // node made
		} // ��� ���� �� insert�̱� ������ ��尡 1�� �����ߴٸ� pHeader==NULL�� �ȴ�. ���� pHeader==NULL�϶��� �����ؾߵ�.

		else {

			pVisited = pHeader;
			pPrev = NULL;				 // pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

			while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited�� �տ� ���� �� null�� ������ runtime ������ �߻��Ѵ�.(pVisited->data ���� X). �ذ���1. ���࿬�� �̿�-> &&�϶� �� ������ false�� �ڿ��� �Ⱥ�(pVisited != NULL�� �տ� �д�)
				pPrev = pVisited;
				pVisited = pVisited->link;
				// if(pVisited == NULL) break;		�ذ���2. (pVisited != NULL)�� ���ǿ��� ���� while�� �ȿ� �־� if(pVisited == NULL) break;�� while���� ���Ǻ��� ���� ���� �ǵ��� �Ѵ�.
			} // while

			if (pPrev == NULL) {	// insert to the first node
				pInput->link = pHeader;
				pHeader = pInput;					// pHeader�� ����Ű�� ù��° ��� �տ� pInput�� ������ pInput�� ù��° ���� �����
			} else {					// insert
				pInput->link = pPrev->link;					
				pPrev->link= pInput;				// pInput�� ������ �� pInput->link�� �� ���� ���� ��带 ����Ű�� ������� link�� pInput�� ������ ����ü�� �����Ѵ�
			}

		} // if-else

		printf("\tData Update : %d -> %d \n",nExistData, nUpdateData);
		break;

	case UNORDERED :			// unordered�� �׳� ���� ������ ���� ��ġ�� ���� retrieve part���� ã�ұ� ������ �� ���� �����Ϳ� ������ ���� ������ �ȴ�.

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
	printf("\t>>");			// print menu�� â�� ����
	scanf("%d",&nMenu);	// �Է¹��� ���� nMenu�� ����

	if (nMenu == PREVIOUS) return;	// 0�� �Է��ϸ� ���θ޴��� ���ư���

	if (nMenu == SEQUENCE || nMenu == REVERSE) printList(nMenu);		// 1�̰ų� 2�� �Է��ϸ� printList(nMenu)�� �����Ѵ�.

	else {
		printf("\t	 WRONG INPUT  NUMBER!!\n");			// �� �� ��ȣ�� �Է��ϸ� wrong input number!!�� ���� ���θ޴��� ���ư���
	}
} //printMenu()	

void printList(int option)	{

	ListNode * pVisited = pHeader; // ù��° ��带 ����Ŵ

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	  LIST DATA\n");
	printf("\t------------------------------\n");

	if (pHeader == NULL) {  // pHeader�� NULL�϶� �� ����Ʈ�� ��尡 ���� ���� ������ EMPTY��� ����

		printf("\t	  E M P T Y\n");
		printf("\t------------------------------\n");
	} else {
		switch(option) {   // printList()���� nMenu�� ���� ���� case�� ����ȴ�.

		case SEQUENCE:  // nMenu�� 1�϶� ����ȴ�. 

			while(pVisited != NULL) { // pVisited�� NULL�϶�����, �� ������ ����϶����� �������� �Ѿ�鼭 ����� ���� ����Ѵ�

				printf("\t	  %5d\n",pVisited->data);
				printf("\t------------------------------\n");
				pVisited = pVisited->link;			// �������� �̵�

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

void initFunc() {    // ���θ޴��� �ʱ�ȭ�Ѵ� (�����ʱ�ȭ ����)

	ListNode *pVisited;
	char ch;

	system("cls");
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t	INIT MENU\n");
	printf("\t------------------------------\n");

	printf("\t init(y/n)? >> ");
	fflush(stdin);
	scanf("%c",&ch);  // �̴��� ������ ���ΰ��� ���� ������� �Է��� �޴´�.

	if (ch=='y' || ch=='Y') {
		while(pHeader !=NULL) {
			pVisited = pHeader;
			pHeader = pVisited->link;	// pHeader�� NULL�� ����ų������ ��� ������ �̵��ϸ鼭 pHeader�� �������� �̵��ϸ� pVisited�� �� ����带 ������
			free(pVisited);					// �� �� ��带 �����Ѵ�.
		} // while

		g_nInsertType=NONE;				// �����ʱ�ȭ�̱� ������ �ѹ� insert menu���� ordered�Ǵ� unordered�� ���ϸ� �ϳ��� ��µǴ� ���� insert menu�� �ʱ�ȭ������ �ٲ۴�.
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
					// about()�� ���״�� �� �ܼ����α׷��� ���� �����ϴ� �Լ��̴�. ���� ��������, ���� ���������, ������ ���۱����� ���� ǥ���Ѵ�. 
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
				pPrev = NULL;			// pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

				while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited�� �տ� ���� �� null�� ������ runtime ������ �߻��Ѵ�.(pVisited->data ���� X). �ذ���1. ���࿬�� �̿�-> &&�϶� �� ������ false�� �ڿ��� �Ⱥ�(pVisited != NULL�� �տ� �д�)
					pPrev = pVisited;				// pPrev�� ��������ͷ� pVisited�� ���� ����Ű�� ���� ����Ű��
					pVisited = pVisited->link;		// pVisited�� ���� ���� �̵��Ѵ�.
					// if(pVisited == NULL) break;		�ذ���2. (pVisited != NULL)�� ���ǿ��� ���� while�� �ȿ� �־� if(pVisited == NULL) break;�� while���� ���Ǻ��� ���� ���� �ǵ��� �Ѵ�.
				} 
				if (pPrev == NULL) {	// insert to the first node
					pInput->link = pHeader;
					pHeader = pInput;		// pHeader�� ����Ű�� ù��° ��� �տ� pInput�� ������ pInput�� ù��° ���� �����
				} else {		// insert
					pInput->link = pPrev->link;
					pPrev->link= pInput;			// pInput�� ������ �� pInput->link�� �� ���� ���� ��带 ����Ű�� ������� link�� pInput�� ������ ����ü�� �����Ѵ�
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
				pPrev = NULL;			// pVisited�� pHeader�� ���� ���� ����Ű�� pPrev�� NULL

				while((pVisited != NULL) && (pVisited->data < pInput->data)) { // pVisited�� �տ� ���� �� null�� ������ runtime ������ �߻��Ѵ�.(pVisited->data ���� X). �ذ���1. ���࿬�� �̿�-> &&�϶� �� ������ false�� �ڿ��� �Ⱥ�(pVisited != NULL�� �տ� �д�)
					pPrev = pVisited;				// pPrev�� ��������ͷ� pVisited�� ���� ����Ű�� ���� ����Ű��
					pVisited = pVisited->link;		// pVisited�� ���� ���� �̵��Ѵ�.
					// if(pVisited == NULL) break;		�ذ���2. (pVisited != NULL)�� ���ǿ��� ���� while�� �ȿ� �־� if(pVisited == NULL) break;�� while���� ���Ǻ��� ���� ���� �ǵ��� �Ѵ�.
				} 
				if (pPrev == NULL) {	// insert to the first node
					pInput->link = pHeader;
					pHeader = pInput;		// pHeader�� ����Ű�� ù��° ��� �տ� pInput�� ������ pInput�� ù��° ���� �����
				} else {		// insert
					pInput->link = pPrev->link;
					pPrev->link= pInput;			// pInput�� ������ �� pInput->link�� �� ���� ���� ��带 ����Ű�� ������� link�� pInput�� ������ ����ü�� �����Ѵ�
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