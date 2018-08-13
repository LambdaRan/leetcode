
与运算
    运算规则：0&0=0;  0&1=0;   1&0=0;    1&1=1;
        即：两位同时为“1”，结果才为“1”，否则为0 
    用途：
        清零
        取一个数中指定位
        x=x&1 取代 x=x%2; 

异或运算
    任何一个数异或它自己都等于0  X xor X = 0
    a⊕b = (¬a ∧ b) ∨ (a ∧¬b)
    如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。

    异或也叫半加运算，其运算法则相当于不带进位的二进制加法：二进制下用1表示真，0表示假，
        则异或的运算法则为：0⊕0=0，1⊕0=1，0⊕1=1，1⊕1=0（同为0，异为1），
        这些法则与加法是相同的，只是不带进位，所以异或常被认作不进位加法。


// 从标准输入读入一行
while (getline(cin, line))
{
    TODO
}
// 牛客不能使用
// 使用内存IO流获取string中的每个单词
//#include <sstream>
std::istringstream allWords(string);
std::string word;
while (allWords >> word)
{
    TODO
}

// 打印消息
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}


// 快速排序
template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if(first == last) return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    ForwardIt middle1 = std::partition(first, last, 
                            [pivot](const auto& em){ return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last, 
                            [pivot](const auto& em){ return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
}

// 归并排序
template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

// 插入排序
// insertion sort
for (auto i = v.begin(); i != v.end(); ++i) {
    std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
}

// 二分查找
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={})
{
    // 注意：类型 T 和 Forward 解引用后的类型都必须可隐式转换为
    // 用于 Compare 的 Type1 和 Type2 。
    // 这严格于 lower_bound 要求（见上述）
 
    first = std::lower_bound(first, last, value, comp);
    return first != last && !comp(value, *first) ? first : last;
}

// 选择排序
template<class ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}
// 以随机数填充 vector
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<> dis(0, 9);

std::vector<int> v1(10), v2(10);
std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));

template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);

    while (count > 0) {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
        if (*it < value) {
            first = ++it; 
            count -= step + 1; 
        }
        else
            count = step;
    }
    return first;
}
template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first,last);

    while (count > 0) {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
        if (!(value < *it)) {
            first = ++it;
            count -= step + 1; // 注意 count = count - (step + 1);
        }
        else
            count = step;
    }
    return first;
}