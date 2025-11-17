#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_ID_LEN 10
#define MAX_SUBJECTS 3

// 学生结构体
typedef struct {
    char id[MAX_ID_LEN];      // 学号
    char name[MAX_NAME_LEN];  // 姓名
    int scores[MAX_SUBJECTS]; // 成绩数组
    float average;            // 平均分
    int total;                // 总分
} Student;

// 系统结构体
typedef struct {
    Student* students;        // 学生数组
    int count;                // 当前学生数量
    int capacity;             // 数组容量
} ManagementSystem;

// 函数声明
void initSystem(ManagementSystem* sys);
void freeSystem(ManagementSystem* sys);
void addStudent(ManagementSystem* sys);
void displayAllStudents(ManagementSystem* sys);
void searchById(ManagementSystem* sys);
void searchByName(ManagementSystem* sys);
void modifyStudent(ManagementSystem* sys);
void deleteStudent(ManagementSystem* sys);
void sortByTotalScore(ManagementSystem* sys);
void showStatistics(ManagementSystem* sys);
void saveToFile(ManagementSystem* sys);
void loadFromFile(ManagementSystem* sys);
void printMenu();
void pressAnyKey();

// 初始化系统
void initSystem(ManagementSystem* sys) {
    sys->capacity = 10;
    sys->count = 0;
    sys->students = (Student*)malloc(sizeof(Student) * sys->capacity);
    if (sys->students == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
}

// 释放系统内存
void freeSystem(ManagementSystem* sys) {
    free(sys->students);
    sys->students = NULL;
    sys->count = 0;
    sys->capacity = 0;
}

// 扩容函数
void expandCapacity(ManagementSystem* sys) {
    sys->capacity *= 2;
    Student* temp = (Student*)realloc(sys->students, sizeof(Student) * sys->capacity);
    if (temp == NULL) {
        printf("内存扩容失败！\n");
        freeSystem(sys);
        exit(1);
    }
    sys->students = temp;
    printf("系统容量已扩展到 %d\n", sys->capacity);
}

// 添加学生
void addStudent(ManagementSystem* sys) {
    if (sys->count >= sys->capacity) {
        expandCapacity(sys);
    }

    Student newStudent;

    printf("\n请输入学生信息：\n");

    // 输入学号
    printf("学号: ");
    scanf("%s", newStudent.id);

    // 检查学号是否重复
    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->students[i].id, newStudent.id) == 0) {
            printf("错误：学号 %s 已存在！\n", newStudent.id);
            return;
        }
    }

    printf("姓名: ");
    scanf("%s", newStudent.name);

    printf("请输入三门成绩（语文 数学 英语）: ");
    newStudent.total = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        scanf("%d", &newStudent.scores[i]);
        newStudent.total += newStudent.scores[i];
    }

    newStudent.average = newStudent.total / (float)MAX_SUBJECTS;

    sys->students[sys->count] = newStudent;
    sys->count++;

    printf("学生信息添加成功！\n");
}

// 显示所有学生
void displayAllStudents(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    printf("\n%-12s %-10s %-8s %-8s %-8s %-8s %-8s\n",
        "学号", "姓名", "语文", "数学", "英语", "总分", "平均分");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < sys->count; i++) {
        printf("%-12s %-10s %-8d %-8d %-8d %-8d %-8.2f\n",
            sys->students[i].id,
            sys->students[i].name,
            sys->students[i].scores[0],
            sys->students[i].scores[1],
            sys->students[i].scores[2],
            sys->students[i].total,
            sys->students[i].average);
    }
}

// 按学号查询
void searchById(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    char id[MAX_ID_LEN];
    printf("\n请输入要查询的学号: ");
    scanf("%s", id);

    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->students[i].id, id) == 0) {
            printf("\n查询结果：\n");
            printf("%-12s %-10s %-8s %-8s %-8s %-8s %-8s\n",
                "学号", "姓名", "语文", "数学", "英语", "总分", "平均分");
            printf("------------------------------------------------------------\n");
            printf("%-12s %-10s %-8d %-8d %-8d %-8d %-8.2f\n",
                sys->students[i].id,
                sys->students[i].name,
                sys->students[i].scores[0],
                sys->students[i].scores[1],
                sys->students[i].scores[2],
                sys->students[i].total,
                sys->students[i].average);
            return;
        }
    }

    printf("未找到学号为 %s 的学生！\n", id);
}

// 按姓名查询
void searchByName(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("\n请输入要查询的姓名: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->students[i].name, name) == 0) {
            if (!found) {
                printf("\n查询结果：\n");
                printf("%-12s %-10s %-8s %-8s %-8s %-8s %-8s\n",
                    "学号", "姓名", "语文", "数学", "英语", "总分", "平均分");
                printf("------------------------------------------------------------\n");
            }
            printf("%-12s %-10s %-8d %-8d %-8d %-8d %-8.2f\n",
                sys->students[i].id,
                sys->students[i].name,
                sys->students[i].scores[0],
                sys->students[i].scores[1],
                sys->students[i].scores[2],
                sys->students[i].total,
                sys->students[i].average);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到姓名为 %s 的学生！\n", name);
    }
}

// 修改学生信息
void modifyStudent(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    char id[MAX_ID_LEN];
    printf("\n请输入要修改的学生学号: ");
    scanf("%s", id);

    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->students[i].id, id) == 0) {
            printf("找到学生: %s %s\n", sys->students[i].id, sys->students[i].name);
            printf("请输入新的姓名（当前: %s）: ", sys->students[i].name);
            scanf("%s", sys->students[i].name);

            printf("请输入新的三门成绩（语文 数学 英语）（当前: %d %d %d）: ",
                sys->students[i].scores[0], sys->students[i].scores[1], sys->students[i].scores[2]);

            sys->students[i].total = 0;
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                scanf("%d", &sys->students[i].scores[j]);
                sys->students[i].total += sys->students[i].scores[j];
            }

            sys->students[i].average = sys->students[i].total / (float)MAX_SUBJECTS;
            printf("学生信息修改成功！\n");
            return;
        }
    }

    printf("未找到学号为 %s 的学生！\n", id);
}

// 删除学生
void deleteStudent(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    char id[MAX_ID_LEN];
    printf("\n请输入要删除的学生学号: ");
    scanf("%s", id);

    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->students[i].id, id) == 0) {
            printf("确定要删除学生 %s %s 吗？(y/n): ",
                sys->students[i].id, sys->students[i].name);

            char confirm;
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {
                // 将后面的元素前移
                for (int j = i; j < sys->count - 1; j++) {
                    sys->students[j] = sys->students[j + 1];
                }
                sys->count--;
                printf("学生信息删除成功！\n");
            }
            else {
                printf("取消删除操作。\n");
            }
            return;
        }
    }

    printf("未找到学号为 %s 的学生！\n", id);
}

// 按总分排序（冒泡排序）
void sortByTotalScore(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    for (int i = 0; i < sys->count - 1; i++) {
        for (int j = 0; j < sys->count - 1 - i; j++) {
            if (sys->students[j].total < sys->students[j + 1].total) {
                // 交换
                Student temp = sys->students[j];
                sys->students[j] = sys->students[j + 1];
                sys->students[j + 1] = temp;
            }
        }
    }

    printf("按总分从高到低排序完成！\n");
    displayAllStudents(sys);
}

// 显示统计信息
void showStatistics(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息！\n");
        return;
    }

    float subjectSums[MAX_SUBJECTS] = { 0 };
    const char* subjectNames[] = { "语文", "数学", "英语" };

    for (int i = 0; i < sys->count; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            subjectSums[j] += sys->students[i].scores[j];
        }
    }

    printf("\n各科目平均分统计：\n");
    printf("-------------------\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("%s平均分: %.2f\n", subjectNames[i], subjectSums[i] / sys->count);
    }

    // 计算总分平均分
    float totalSum = 0;
    for (int i = 0; i < sys->count; i++) {
        totalSum += sys->students[i].total;
    }
    printf("总分平均分: %.2f\n", totalSum / sys->count);
}

// 保存到文件
void saveToFile(ManagementSystem* sys) {
    if (sys->count == 0) {
        printf("\n没有学生信息可保存！\n");
        return;
    }

    FILE* file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("无法打开文件进行保存！\n");
        return;
    }

    // 先写入学生数量
    fwrite(&sys->count, sizeof(int), 1, file);

    // 写入所有学生数据
    fwrite(sys->students, sizeof(Student), sys->count, file);

    fclose(file);
    printf("学生数据已保存到 students.dat（共 %d 条记录）\n", sys->count);
}

// 从文件读取
void loadFromFile(ManagementSystem* sys) {
    FILE* file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("没有找到数据文件或文件为空！\n");
        return;
    }

    // 读取学生数量
    int count;
    fread(&count, sizeof(int), 1, file);

    if (count <= 0) {
        printf("文件数据无效！\n");
        fclose(file);
        return;
    }

    // 确保容量足够
    while (sys->capacity < count) {
        expandCapacity(sys);
    }

    // 读取学生数据
    fread(sys->students, sizeof(Student), count, file);
    sys->count = count;

    fclose(file);
    printf("从文件加载了 %d 条学生记录\n", count);
}

// 打印菜单
void printMenu() {
    printf("\n====== 学生成绩管理系统 ======\n");
    printf("1. 添加学生信息\n");
    printf("2. 显示所有学生\n");
    printf("3. 按学号查询\n");
    printf("4. 按姓名查询\n");
    printf("5. 修改学生信息\n");
    printf("6. 删除学生信息\n");
    printf("7. 按成绩排序\n");
    printf("8. 统计信息\n");
    printf("9. 保存到文件\n");
    printf("10. 从文件读取\n");
    printf("0. 退出系统\n");
    printf("==============================\n");
    printf("请选择操作（0-10）: ");
}

// 按任意键继续
void pressAnyKey() {
    printf("\n按任意键继续...");
    getchar(); // 清除缓冲区
    getchar(); // 等待按键
}

// 主函数
int main() {
    ManagementSystem sys;
    initSystem(&sys);

    int choice;

    printf("欢迎使用学生成绩管理系统！\n");

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: addStudent(&sys); break;
        case 2: displayAllStudents(&sys); break;
        case 3: searchById(&sys); break;
        case 4: searchByName(&sys); break;
        case 5: modifyStudent(&sys); break;
        case 6: deleteStudent(&sys); break;
        case 7: sortByTotalScore(&sys); break;
        case 8: showStatistics(&sys); break;
        case 9: saveToFile(&sys); break;
        case 10: loadFromFile(&sys); break;
        case 0:
            printf("感谢使用，再见！\n");
            break;
        default:
            printf("无效的选择，请重新输入！\n");
        }

        if (choice != 0) {
            pressAnyKey();
        }

    } while (choice != 0);

    freeSystem(&sys);
    return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[100];
    char* description;

    strcpy(name, "Zara Ali");

    /* 动态分配内存 */
    description = (char*)malloc(30 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcpy(description, "Zara ali a DPS student.");
    }
    /* 假设您想要存储更大的描述信息 */
    description = (char*)realloc(description, 100 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcat(description, "She is in class 10th");
    }

    printf("Name = %s\n", name);
    printf("Description: %s\n", description);

    /* 使用 free() 函数释放内存 */
    free(description);
}





















