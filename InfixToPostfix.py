# Converting an Infix Expression to Postfix expression.
Infix = input("Enter an Infix expression: ")
Operators1 = ['/','%','*']
Operators2 = ['+','-']
Postfix = []
Stack = []

for i in Infix:
    if i.isalpha():
        Postfix.append(i)
        #print("Is alpha: ", Stack, Postfix)
    elif len(Stack) == 0 or i == '(' or Stack[-1] == '(':
        Stack.append(i)
        #print("Is ( or Stack is ) or Length is 0: ", Stack, Postfix)
    elif i == ')':
        while Stack[-1] != '(':
            Postfix.append(Stack.pop())
        Stack.pop()
        #print("Is i is ): ", Stack, Postfix)
    else:
        Rank = 2 if i in Operators1 else 1
        RankStack = 2 if Stack[-1] in Operators1 else 1
        if RankStack < Rank:
            Stack.append(i)
            #print("Is Rank > RankStack: ", Stack, Postfix, Rank, RankStack)
        else:
            Postfix.append(Stack.pop())
            Stack.append(i)
            #print("Is Rank < RankStack: ", Stack, Postfix, Rank, RankStack)
while len(Stack) != 0:
    Postfix.append(Stack.pop())
#print("Is Final:  ", Stack, Postfix)
print()
print("Given", Infix, " Postfix expression is: ", ''.join(Postfix))