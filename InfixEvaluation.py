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
    if token.isdigit():  # if token is a digit, then add it into ValueStack
        ValueStack.append(int(token))
    
    elif not OperatorStack or token == '(':  # if OperatorStack is empty or token is an open parentheses then add it into OperatorStack
        OperatorStack.append(token)
    
    elif token == ')':  
        '''
        if token is a right parenthesis:
         >>> While the thing on top of the operator stack is not a left parenthesis,
             1. Pop the operator from the operator stack.
             2. Pop the value stack twice, getting two operands.
             3. Apply the operator to the operands, in the correct order.
             4. Push the result onto the value stack.
         >>> Pop the left parenthesis from the operator stack, and discard it.
         
         '''
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
            '''
            >>> While the operator stack is not empty, and the top thing on the operator stack has the same or greater precedence as token,
                1. Pop the operator from the operator stack.
                2. Pop the value stack twice, getting two operands.
                3. Apply the operator to the operands, in the correct order.
                4. Push the result onto the value stack.
            >>> Push token into the operator stack.'''
            while OperatorStack and Ranks[token] <= Ranks[OperatorStack[-1]]:
                x = ValueStack.pop()
                y = ValueStack.pop()
                oper = OperatorStack.pop()
                Res = Eval(y,x,oper)
                ValueStack.append(Res)
            OperatorStack.append(token)
while OperatorStack:
    '''
    >>> While the operator stack is not empty,
        1 Pop the operator from the operator stack.
        2 Pop the value stack twice, getting two operands.
        3 Apply the operator to the operands, in the correct order.
        4 Push the result onto the value stack.
    '''
    x = ValueStack.pop()
    y = ValueStack.pop()
    oper = OperatorStack.pop()
    Res = Eval(y,x,oper)
    ValueStack.append(Res)
# ValueStack contains only one value.
print(ValueStack)  # ((2/12)+23)*2