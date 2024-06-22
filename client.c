#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WORNINGS

// Client �ʱ�ȭ �Լ�
void Client_Init(Client* client)
{
    client->id = 0;
    strcpy(client->name, "");
    strcpy(client->gender, "");
    strcpy(client->birthday, "");
    strcpy(client->phone_number, "");
    client->visit = 0;
    client->mileage = 0;
    strcpy(client->service_history, "");
}

// Client �ʱ�ȭ �Լ� (�Ű����� �ִ� ����)
void Client_InitWithParams(Client* client, int id, const char* name, const char* gender, const char* birthday, const char* phone_number, int visit, int mileage, const char* service_history)
{
    client->id = id;
    strncpy(client->name, name, sizeof(client->name) - 1);
    strncpy(client->gender, gender, sizeof(client->gender) - 1);
    strncpy(client->birthday, birthday, sizeof(client->birthday) - 1);
    strncpy(client->phone_number, phone_number, sizeof(client->phone_number) - 1);
    client->visit = visit;
    client->mileage = mileage;
    strncpy(client->service_history, service_history, sizeof(client->service_history) - 1);
}

// client�� ���ϸ��� ����
void Client_SaveMileage(Client* client, int cost)
{
    int temp = cost * 0.1;
    client->mileage += temp;
}

// int ������ ����
void Client_PutIntData(Client* client, data_type type, int data)
{
    switch (type)
    {
    case ID:
        client->id = data;
        break;
    case VISIT:
        client->visit = data;
        break;
    case MILEAGE:
        client->mileage = data;
        break;
    default:
        printf("Type entered does not exist\n");
        break;
    }
}

// string ������ ����
void Client_PutStringData(Client* client, data_type type, const char* data)
{
    switch (type)
    {
    case NAME:
        strncpy(client->name, data, sizeof(client->name) - 1);
        break;
    case GENDER:
        strncpy(client->gender, data, sizeof(client->gender) - 1);
        break;
    case BIRTHDAY:
        strncpy(client->birthday, data, sizeof(client->birthday) - 1);
        break;
    case PHONE_NUMBER:
        strncpy(client->phone_number, data, sizeof(client->phone_number) - 1);
        break;
    case SERVICE_HISTORY:
        strncpy(client->service_history, data, sizeof(client->service_history) - 1);
        break;
    default:
        printf("Type entered does not exist\n");
        break;
    }
}

// client ���� ���
void Client_PrintInfo(const Client* client)
{
    printf("�̸� : %s\n", client->name);
    printf("���� : %s\n", client->gender);
    printf("���� : %s\n", client->birthday);
    printf("��ȭ��ȣ : %s\n", client->phone_number);
    printf("�湮Ƚ�� : %d\n", client->visit);
    printf("���ϸ��� : %d\n", client->mileage);
    printf("���� ���� : %s\n", client->service_history);
}

// client�� ���ϸ��� ���
int Client_PayMileage(Client* client, int cost)
{
    if (client->mileage < 100)
    {
        printf("���ϸ����� ������� �ʽ��ϴ�\n");
        return cost;
    }
    else
    {
        int temp = client->mileage - cost;
        if (temp < 0)
        {
            client->mileage = 0;
            return cost - client->mileage;
        }
        else
        {
            client->mileage -= cost;
            return 0;
        }
    }
}

// int ������ ��������
int Client_GetIntData(const Client* client, data_type type)
{
    switch (type)
    {
    case ID:
        return client->id;
    case VISIT:
        return client->visit;
    case MILEAGE:
        return client->mileage;
    default:
        printf("Type entered does not exist\n");
        return -1;
    }
}

// string ������ ��������
const char* Client_GetStringData(const Client* client, data_type type)
{
    switch (type)
    {
    case NAME:
        return client->name;
    case GENDER:
        return client->gender;
    case BIRTHDAY:
        return client->birthday;
    case PHONE_NUMBER:
        return client->phone_number;
    case SERVICE_HISTORY:
        return client->service_history;
    default:
        printf("Type entered does not exist\n");
        return NULL;
    }
}

// Ŭ���̾�Ʈ�� csv �������� ��ȯ
char* Client_ToCSV(Client* client) {
    // CSV ������ ���ڿ��� ������ �޸𸮸� �Ҵ��մϴ�.
    // �ʿ��� ���̸� ����Ͽ� �޸𸮸� �Ҵ��մϴ�.
    int bufferSize = 50 + 10 + 20 + 20 + 100 + 50; // �뷫���� ���� ���
    char* buffer = (char*)malloc(bufferSize);

    if (buffer == NULL) {
        perror("Unable to allocate memory for CSV string");
        exit(EXIT_FAILURE);
    }

    // snprintf�� ����Ͽ� Ŭ���̾�Ʈ �����͸� CSV �������� ��ȯ�մϴ�.
    snprintf(buffer, bufferSize, "%d,%s,%s,%s,%s,%d,%d,%s",
        client->id,
        client->name,
        client->gender,
        client->birthday,
        client->phone_number,
        client->visit,
        client->mileage,
        client->service_history);

    char* newline = strchr(buffer, '\n');
    if (newline)
        *newline = '\0';

    return buffer;
}