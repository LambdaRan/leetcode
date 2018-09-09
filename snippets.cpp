
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

// 打印vector<pair<int, int>>
void printVectorPair(vector<pair<int, int>>& vp)
{
    for (auto& v : vp)
        cout << 'f: ' << v.first << " s: " << v.second << "\n";
}

// 计算数组大小
template <class T, std::size_t N>
constexpr std::size_t size(const T (&pArray)[N]) noexcept
{
    return (void)pArray, N;
}


string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

int main()
{
    string line = "";
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string number = "0123456789";
    typedef pair<int, string> Entry;
    while (getline(cin, line))
    {
        set<Entry> letterSet;
        size_t start = 0;
        while (start < line.size())
        {
            auto ret1 = line.find_first_not_of(alpha, start);
            string letter = string(line, start, ret1-start);
            auto ret2 = line.find_first_not_of(number, ret1);
            int size = stoi(string(line, ret1, ret2-ret1));
            letterSet.insert(make_pair(size, letter));
            start = ret2;
        }
    }

    return 0;
}

vector<string> strSplit(const string& str, char dem)
{
    vector<string> vs;
    size_t start = 0;
    size_t size = str.size();
    while (start < size)
    {
        auto ret = str.find_first_of(dem, start);
        ret = (ret == string::npos) ? size : ret;
        vs.emplace_back(str.substr(start, ret-start));
        start = ret + 1;
    }
    return vs;
}
// #include <sstream>
// #include <cctype>
vector<int> strSplit(string input, char delim) 
{
    vector<int> output;
    // trimLeftTrailingSpaces(input);
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
    // trimRightTrailingSpaces(input);
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
    //input = input.substr(1, input.length() - 2);
    istringstream ss(input);
    // ss.str(input);
    string item;
    // char delim = ',';
    while (getline(ss, item, delim)) {
        output.emplace_back(stoi(item));
    }
    return output;
}

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

vector<int> stringToIntegerVector(string input) 
{
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


// 堆排序
void heapSort_v1(int *arr, int n)
{
    std::make_heap(arr, arr+n);
    for (int i = n; i > 0; --i)
        std::pop_heap(arr, arr+i);
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

// 首先，从尾端开始往前寻找两个相邻元素，令第一个元素为*i,第二个元素为*ii,且满足*i < * ii,
// 找到这样一组相邻元素后，在从最尾端往前检查，找到第一个大于*i的元素，令为*j,将i,j元素对调，
// 再将ii之后的所有元素颠倒排列。 这就是下一个排列组合
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}
// 首先从最尾端开始往前寻找两个相邻的元素，令第一个元素为*i, 第二个元素为*ii,且满足*i > *ii,
// 找到这样的相邻元素后，再从最尾端开始往前检验，找到第一个小于*i的元素，令为*j,将i,j元素对调，
// 再将ii之后的所有元素颠倒排列。此为前一个排列组合

template<class BidirIt>
bool prev_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (1) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*i1 < *--i) {
            i2 = last;
            while (!(*--i2 < *i))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}
vector<string> Permutation(string str)
{
    if (str.empty()) return vector<string>();
    size_t strSize = str.size();
    if (strSize == 1) 
    {
        vector<string> ret;
        ret.push_back(str);
        return ret;
    } 
    
    set<string> result;
    result.insert(str);
    bool loop = true;
    while (loop)
    {
        size_t head = strSize - 1;
        while (true)
        {
            size_t tailOne = head;
            // 找到左边字符小于右边字符位置
            // 如：1，4，5，3，2 
            // head：4  tailOne:5
            if (str[--head] < str[tailOne]) 
            {
                size_t tailTwo = strSize;
                // 从右到左找到第一个大于head所指字符的位置
                // 如：1，4，5，3，2
                // head:4   tailTwo:5
                while (!(str[head] < str[--tailTwo]));

                std::swap(str[head], str[tailTwo]);
                std::reverse(str.begin()+tailOne, str.end());
                
                result.insert(str);
                break;
            }

            if (head == 0)
            {
                std::reverse(str.begin(), str.end());
                loop = false;
                break;
            }
        }
    }
    return vector<string>(result.begin(), result.end());
}
