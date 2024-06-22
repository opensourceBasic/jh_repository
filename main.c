#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "data_handler.h"
#include "system_menu.h"

int main() {
    const char* filename = "clients.csv";
    const char* filename_t = "test.csv";

    // DataHandler �ʱ�ȭ
    DataHandler* handler = DataHandler_Create();
    DataHandler_ReadCSV(handler, filename);

    // Display �ʱ�ȭ
    Display display;
    Display_Init(&display, handler);

    // �޴� ���
    Display_ShowMenu(&display);

    // �����ͺ��̽��� CSV ���Ͽ� ����
    DataHandler_WriteCSV(handler, filename_t);

    // DataHandler �޸𸮸� ����
    DataHandler_Destroy(handler);

    return 0;
}