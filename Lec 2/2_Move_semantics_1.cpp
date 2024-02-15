int main()
{
    int i = 42;
    int &&rr = i * 42;

    int i; // Ivalue
    i = 1;

    int* ip; // Ivalue
    *ip = 1;

    int i; //prvalue
    i  = 1;

    float f( ) {  //Ivalue
    float f;
    return f;
    }

    float f( ) {  //prvalue
    return 2;
    }

    float&& f ( ) {  //xvalue
    return 2;
    }
}

