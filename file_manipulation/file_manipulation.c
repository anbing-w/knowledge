#include <stdio.h>
#include <stdlib.h>

#ifdef __FILE_TEST
int main(void)
{
    FILE *fp = fopen("F:\\internship\\C_language\\knowledge\\test.txt", "r");
    if (NULL == fp)
    {
        puts("文件打开失败！！\n");
    }
    else
    {
        puts("文件打开成功！！\n");
    }
    int result = fclose(fp);
    if (result == 0)
    {
        puts("成功关闭文件！！\n");
    }
    else
    {
        puts("关闭文件失败！！\n");
    }
}
#elif __FILE__READ

int main(void)
{
    int number = 0;
    char name[20];
    int chinese;
    int math;
    int chinese_sum = 0;
    int math_sum = 0;
    FILE *fp = fopen("F:/internship/C_language/knowledge/test.txt", "r");
    if (fp != NULL)
    {
        puts("开始读取数据");
        while (fscanf(fp, "%s%d%d", name, &chinese, &math) == 3)
        {
            printf("%s %d %d\n", name, chinese, math);
            number++;
            chinese_sum += chinese;
            math_sum += math;
        }
        puts("-------------");
        printf("平均 %d %d\n", chinese_sum / number, math_sum / number);
    }
    else
    {
        puts("文件打开失败");
    }
    int result = fclose(fp);
    if (result == 0)
    {
        puts("成功关闭文件");
    }
    else
    {
        puts("文件关闭失败");
    }
    return 0;
}
#elif __WRITE_CURRENT_TIME

// 向文件中写入当前时间

#include <time.h>

#if 0
/**
 * @description 定义一个日期类型的结构体
 */
typedef struct Date
{
    struct tm *local;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Date;

char *get_date_format()
{
    return "%.4d/%.2d/%.2d %.2d:%.2d:%.2d";
}

void readTimeTxt(char *path)
{
    FILE *read = fopen(path, "r");
    if (read == NULL)
    {
        printf("读书的文件不存在");
        // exit(-1);
        return;
    }
    int year, month, day, hour, minue, second;
    char line[100];
    // int result=fscanf(read, "%[^\n]\n", line);
    // printf("%d\n",result);
    /*if(result==EOF)
    {
        puts("读取文件出现错误。。。。");
    }else
    {
        puts(line);
    }
    // 问题出现，无法读取空格问题
    while(fscanf(read, "%d/%d/%d %d:%d:%d", &year,&month,&day,&hour,&minue,&second)==6)
    {
        //fscanf(read, "\n");
        printf("read time:%d/%d/%d %d:%d:%d\n",year,month,day,hour,minue,second);
    }*/

    // 直接读取一行数据包括空格，但是不能转换为对象，需要从字符中截取才行
    while (fscanf(read, "%[^\n]\n", line) == 1)
    {
        // fscanf(read, "\n");
        printf("read time:%s\n", line);
    }
    fclose(read);
}

/**
 * @description 将当前的tm时间转换为对应的结构体Date
 * @param local
 * @return
 */
struct Date convertToDate(struct tm *local)
{
    Date date;
    date.year = local->tm_year + 1900;
    date.month = local->tm_mon + 1;
    date.day = local->tm_mday;
    date.hour = local->tm_hour;
    date.minute = local->tm_min;
    date.second = local->tm_sec;
    return date;
}

struct Date get_current_time()
{
    time_t t;
    struct tm *local;
    time(&t);
    local = localtime(&t);
    return convertToDate(local);
}

void writeTimeTxt(char *path)
{
    FILE *write = fopen(path, "a");
    if (write == NULL)
    {
        printf("写入的文件不存在");
        // exit(-1);
        return;
    }
    struct Date date = get_current_time();

    fprintf(write, get_date_format(), date.year, date.month, date.day, date.hour, date.minute, date.second);
    fprintf(write, "\n");

    fclose(write);
}

int main()
{

    char path[] = "F:\\internship\\C_language\\knowledge\\a.txt";
    /* puts("请输入需要读取的日期文本数据:");*/
    writeTimeTxt(path);
    puts("写入日期数据到文件中成功！");
    /*scanf("%s",path);*/
    readTimeTxt(path);
    puts("读取日期数据文件中成功！");
    // 写入数据没有问题
    // writeTimeTxt(path);
    return 0;
}
#endif

#include <time.h>

int main(void)
{
    char line[100];
    FILE *fp;
    time_t currentTime = time(NULL);                 // 得到系统的日历时间
    struct tm *timeStruct = localtime(&currentTime); // 得到本地时间
    if ((fp = fopen("F:\\internship\\C_language\\knowledge\\test.txt", "w")) != NULL)
    {
        puts("将当前日期和时间保存至文件");
        int year = timeStruct->tm_year + 1900;
        int month = timeStruct->tm_mon + 1;
        int day = timeStruct->tm_mday;
        int hour = timeStruct->tm_hour;
        int minute = timeStruct->tm_min;
        int second = timeStruct->tm_sec;
        fprintf(fp, "%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second); // 将读取到的时间保存到文件中
        // fscanf(fp, "%[^\n]\n", line);
        // printf("read time: %s\n", line);
        fclose(fp);
    }

    return 0;
}

#elif __FILE_CONTENTS_DISPLAY
// 将文件内容显示至工作台

#if 0
int main()
{
    int ch;
    FILE *fp;
    char fileName[FILENAME_MAX];
    printf("Please input the path of the file:\n");
    scanf("%s", fileName);
    if((fp = fopen(fileName, "r")) == NULL)
    {
        puts("Couldn't open the file");
    }
    else
    {
        while((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }
        fclose(fp);
    }
    return 0;
}
#endif

int main()
{
    int ch;
    FILE *sfp;
    FILE *dfp;
    char sName[FILENAME_MAX];
    char dName[FILENAME_MAX];
    printf("please input the path of the source file:\n");
    scanf("%s", sName);
    printf("please input the path of the object file:\n");
    scanf("%s", dName);
    if ((sfp = fopen(sName, "r")) == NULL)
    {
        puts("Couldn't open the source file\n");
    }
    else
    {
        if ((dfp = fopen(dName, "a")) == NULL)
        {
            puts("Couldn't open the object file\n");
        }
        else
        {
            while ((ch = fgetc(sfp)) != EOF)
            {
                fputc(ch, dfp);
            }
            fclose(dfp);
            fclose(sfp);
        }
    }
    return 0;
}
#else

/**
 * @brief 文件中写入字符串
 *
 */
/* int main()
{
    FILE *fp = fopen("F:\\internship\\C_language\\knowledge\\test1.txt", "w");
    fputs("hello c programming\n", fp);
    fputs("hello c++ programming\n", fp);
    fclose(fp);
    puts("已将字符串写入文件");
    return 0;
} */

/**
 * @brief 知道文件内容，可以这样读取两次
 *
 * @return int
 */
/*
int main()
{
   char str[300];
   FILE *fp= fopen("F:\\internship\\C_language\\knowledge\\test1.txt", "r");
   //读取第一行的内容
   char *strLine1=fgets(str, 200, fp);
   printf("%s",strLine1);
   //读取第二行的内容
   char *strLine2=fgets(str, 200, fp);
   printf("%s",strLine2);
   fclose(fp);
   return 0;
} */

/**
 * @brief 上面代码改进
 *
 */

/* int main()
{
    char str[300];
    FILE *fp= fopen("F:\\internship\\C_language\\knowledge\\test1.txt", "r");
    char *stringLine;
    while((stringLine=fgets(str, 200, fp))!=NULL){
        printf("%s",stringLine);
    }
    fclose(fp);
    return 0;
} */

// 利用fwrite()写数据
//  size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
//  int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
/* int main()
{
    FILE *fp;
    int buffer[] = {9, 5, 2, 7};
    if ((fp = fopen("F:\\internship\\C_language\\knowledge\\test1.txt", "wb")) != NULL)
    {
        fwrite(buffer, sizeof(int), 4, fp);
        fclose(fp);
    }
    puts("已将数据按照二进制的形式存入文件");
    return 0;
}
 */


//利用fread()读数据
/* int main()
{
    int i;
    FILE * fp;
    int buffer[4];
    if((fp = fopen ("F:\\internship\\C_language\\knowledge\\test1.txt", "rb"))!=NULL){
        fread(buffer, sizeof(int), 4, fp);
        fclose (fp);
    }
    for(i=0;i<4;i++){
        printf("%d ",buffer[i]);
    }
    return 0;
}
 */


//利用fwrite()写结构体数据
/* typedef struct{
    int age;
    char name[20];
}Student;
 
int main()
{
    int i;
    FILE * fp;
    Student stu1={18,"zxx"};
    Student stu2={19,"hmm"};
    Student stu3={29,"lqn"};
    Student studentArray[3]={stu1,stu2,stu3};
    if((fp = fopen ("F:\\internship\\C_language\\knowledge\\test1.txt", "wb"))!=NULL){
        for(i=0;i<3;i++){
            fwrite(&studentArray[i],sizeof(Student),1,fp);
        }
        puts("已将结构体类型数据按照二进制的形式存入文件");
        fclose (fp);
    }
    return 0;
} */

//利用fread()读数据
typedef struct{
    int age;
    char name[20];
}Student;
 
int main()
{
    FILE *fp;
    Student stu;
    if((fp = fopen ("F:\\internship\\C_language\\knowledge\\test1.txt", "rb"))!=NULL){
        while((fread(&stu,sizeof(Student),1,fp))==1){
            printf("%d %s\n",stu.age,stu.name);
        }
        fclose(fp);
    }
    return 0;
}

#endif // DEBUG 0
