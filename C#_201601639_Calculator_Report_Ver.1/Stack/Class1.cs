using System;


namespace Calculator
{
    public class Stack
    {
        private const string ERROR = "접근할 수 없습니다.";

        public int Peek { get; private set; }       //스택의 최상위를 가리킴
        public string[] Stack_operator { get; private set; }    //스택 배열

        public Stack()
        {
            Stack_operator = new string[20];       //임의로 100만큼의 크기 할당
            Peek = -1;                              //-1로 초기화
        }
        #region//Push
        protected void Push(string temp_oper)
        {
            if (Peek != 20)
            {
                Stack_operator[++Peek] = temp_oper;     //Peek + 1 의 공간에 연산자 푸쉬
            }
            else
            {
                Console.WriteLine(ERROR);
            }
        }
        #endregion

        #region//Pop
        protected string Pop()
        {
            string temp_pop = null;
            if (Peek != -1)
            {
                temp_pop = Stack_operator[Peek];
                Stack_operator[Peek--] = null;
            }
            else
            {
                Console.WriteLine(ERROR);
            }
            return temp_pop;
        }
        #endregion

        #region//Clear
        public void Clear()
        {
            Array.Clear(Stack_operator, '\0', 20);
            Peek = -1;
        }
        #endregion

        #region//isEmpty
        public bool isEmpty()
        {
            if (Peek == -1)
                return true;
            else
                return false;
        }
        #endregion
    }
}