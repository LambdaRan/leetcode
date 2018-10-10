

/**
*函数原型：
*  void perror( char const *message );//打印 message 和 解释errno当前错误代码的信息
*
*  FILE *fopen( char const *name, char const *mode );//打开一个特定的流
*  FILE *freopen( char const *filename, char const *mode, FILE *stream );//打开（重新打开）一个特定的流
*  int fclose( FILE *f );//关闭流
*
*  int fgetc( FILE *stream );//字符输入  任何流
*  int getc( FILE *stream );//字符输入  define定义的 宏
*  int getchar( void );//字符输入，用于标准输入流stdin  define定义的 宏
*  int fputc( int character, FILE *stream );//字符输出  任何流
*  int putc( int character, FILE *stream );//字符输出  define定义的 宏
*  int putchar( int character );//字符输出，用于标准输出流stdout  define定义的 宏
*  int ungetc( int character, FILE *stream );//把先前读入的字符返回到流中
*未格式化：
*  char *fgets( char *buffer, int buffer_size, FILE *stream );//文本行输入（字符串输入） 任何流
*  char *gets( char *buffer );//文本行输入（字符串输入）  标准输入流stdin
*  char fputs( char *buffer, int buffer_size, FILE *stream );//文本行输出（字符串输出）  任何流
*  char puts( char *buffer );//文本行输出（字符串输出）  标准输出流stdout
*格式化：
*  int fscanf( FILE *stream, char const *format, ... );
*  int scanf( char const *format, ... );
*  int sscanf( char const *string, char const *format, ... );
*  int fprintf( FILE *stream, char const *format, ... );
*  int printf( char const *format, ... );
*  int sprintf( char const *string, char const *format, ... );
*二进制：
*  size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
*  size_t fwrite( void *buffer, size_t size, size_t count, FILE *stream );
*
*  int fflush( FILE *stream );//刷新输出缓冲区
*  long ftell( FILE *stream );// 返回流的当前位置
*  int fseek( FILE *stream, long offset, int from );//在流中定位
*  void rewind( FILE *stream );//将读写指针设置回指定流的起始位置,同时清除流的错误标志
*  int fgetpos( FILE *stream, fpos_t *position );
*  int fsetpos( FILE *stream, fpos_t const *position );
*
*改变缓冲方式:流打开为执行任何操作前才能调用
*  void setbuf( FILE *stream, char *buf );
*  void setvbuf( FILE *stream, char *buf, int mode, size_t size );
*流错误函数：
*  int feof( FILE *stream );//流当前处于文件尾
*  int ferror( FILE *stream );//报告流的错误状态
*  void clearerr( FILE *stream );//重置流错误标志
*临时文件：
*  FILE *tmpfile( void ); //创建一个文件，当文件被关闭和程序终止时这个文件便自动删除
*  char *tmpnam( char *name );//创建临时文件的名字
*文件操作函数：
*  int remove( char const *filename );//删除指定文件
*  int rename( char const *oldname, char const *newname );//重命名
*/

/*
*函数原型：
*不受限制 ( size_t 定义在 stddef.h )
*  size_t strlen( char const *string );//求字符串长度
*  char *strcpy( char *dst, char const *src );//字符串复制函数，src --> dst
*  char *strcat( char *dst, char const *src );//字符串连接，dst+src
*  int strcmp(char const *s1, char const *s2);//字符串比较
*长度受限
*  char *strncpy( char *dst, char const *src, size_t len );
*  char *strncat( char *dst, char const *src, size_t len );
*  int strncmp( char const *s1, char const *s2, size_t len );
*
*  char *strchr( char const *str, int ch );//在字符串str中查找特定字符ch 第一次出现位置
*  char *strrchr( char const *str, int ch );//在字符串str中查找特定字符ch 最后一次出现位置
*  char *strpbrk( char const *str, char const *group );//在字符串str中查找group组中任何一个字符第一次出现的位置
*  char *strstr( char const *s1, char const *s2 );//在字符串s1中查找子串s2
*  size_t strspn( char const *str, char const *group );//查找字符串str中从起始位置有连续几个字符在group中
*  size_t strcspn( char const *str, char const *group );//查找字符串str中从起始位置有连续几个字符不在group中
*  char *strtok( char *str, char const *sep );//将字符串str以标记sep 分隔（查找标记）
*  char *strerror( int error_number );//将错误代码errno 返回一个用于描述错误的字符串的指针
*字符分类：ctype.h
*  iscntrl isspace isdigit isxdigit islower isupper isalpha isalnum ispunct isgraph isprint
*字符转换：
*  int tolower( int ch );//转小写
*  int toupper( int ch );//转大写
*内存操作
* void *memcpy( void *dst, void const *src, size_t length );
* void *memmove( void *dst, void const *src, size_t length );
* void *memcmp( void const *a, void const *b, size_t length );;
* void *memcpy( void const *a, int ch, size_t length );
* void *memset( void *a, int ch, size_t length );
*/

/*
clock_t clock(void);//从程序开始执行起处理器所消耗的时间
time_t time(time_t *returned_value);//返回当前时间，秒数

	char *ctime(time_t const *time_value);//时间字符串
	double difftime(time_t time1, time_t time2);//计算time1-time2 并转换成秒
	
	struct tm *gmtime(time_t const *time_value);//格林威治时间
	struct tm *localtime(time_t const *time_value);//当地时间
		
		char *asctime(struct tm const *tm_ptr);//时间字符串
		size_t strftime(char *string, size_t maixsize, char const *format, struct tm const *tm_ptr);//格式化输出时间
		time_t mktime(struct tm *tm_ptr);//将tm结构时间转换成time_t值
*/

// 纯字符串用puts()输出。
// 数据大时最好用scanf()、printf()减少时间。
// 先用scanf()，再用gets()会读入回车。
// scanf("%c%c",&c1,&c2)会读入空格；

int a,d;
// 读到文件的结尾，程序自动结束
while( ( scanf("%d",&a) ) != -1 )
while( ( scanf("%d",&a) ) != EOF)
while( ( scanf("%d",&a) ) == 1 )

// 读到一个0时，程序结束
while( scanf("%d",&a) &&a)

//读到多个0时，程序结束
while( scanf("%d%d%d",&a,&b,&c)&&a+b+c )

int n;
while (scanf("%d", &n) != EOF){
//...
} 

int isPrime(int n)
{
	if(n <= 1) 	return 0;
    for(int i = 2; i*i <= n; ++i)
        if(n%i == 0)	return 0;
    return 1;
}

/*
 * swap - swap value of @a and @b
 */
#define swap(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

/* Greatest common divisor */
//最大的公约数
unsigned long gcd(unsigned long a, unsigned long b)
{
	unsigned long r;

	if (a < b)
		swap(a, b);

	if (!b)
		return a;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
/* Lowest common multiple */
//　最小公倍数
unsigned long lcm(unsigned long a, unsigned long b)
{
	if (a && b)
		return (a / gcd(a, b)) * b;
	else
		return 0;
}

unsigned long lcm_not_zero(unsigned long a, unsigned long b)
{
	unsigned long l = lcm(a, b);

	if (l)
		return l;

	return (b ? : a);
}

