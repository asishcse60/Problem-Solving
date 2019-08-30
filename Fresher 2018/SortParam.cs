
void Sort (ref int a, ref int b){
    if (a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
}