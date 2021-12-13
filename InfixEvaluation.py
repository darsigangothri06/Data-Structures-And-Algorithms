Exp = input("Enter: ")
ValueStack = []
OperatorStack = []
Ranks = {'+': 1, '-': 1, '*': 2, "/": 2, '(': 0}

def Eval(a,b,opr):
    if opr == '-':
        return a - b
    elif opr == '+':
        return a + b
    elif opr == '/':
        return a//b
    return a * b

for token in Exp:
    if token.isdigit():
        ValueStack.append(int(token))
    
    elif not OperatorStack or token == '(':
        OperatorStack.append(token)
    
    elif token == ')':
        while OperatorStack[-1] != '(':
            x = ValueStack.pop()
            y = ValueStack.pop()
            oper = OperatorStack.pop()
            Res = Eval(y,x,oper)
            ValueStack.append(Res)
        OperatorStack.pop()
    
    else:
        if Ranks[token] > Ranks[OperatorStack[-1]]:
            OperatorStack.append(token)
        else:
            while OperatorStack and Ranks[token] <= Ranks[OperatorStack[-1]]:
                x = ValueStack.pop()
                y = ValueStack.pop()
                oper = OperatorStack.pop()
                Res = Eval(y,x,oper)
                ValueStack.append(Res)
            OperatorStack.append(token)
while OperatorStack:
    x = ValueStack.pop()
    y = ValueStack.pop()
    oper = OperatorStack.pop()
    Res = Eval(y,x,oper)
    ValueStack.append(Res)
print(ValueStack)