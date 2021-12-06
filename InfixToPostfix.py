# Converting an Infix Expression to Postfix expression.
Infix = input("Enter an Infix expression: ")
Ranks = {'/': 1, '%':1, '*':1, '+': 0, '-': 0}
Postfix = []
Stack = []

for i in Infix:
    # if character is an alphabet --- then add it into postfix directly
    if i.isalpha():
        Postfix.append(i)
    # if character is an open parantheses or stack is empty, then add i into stack
    elif len(Stack) == 0 or i == '(' or Stack[-1] == '(':
        Stack.append(i)
    # if i is ')' then until we get an '(' pop the stack and push into postfix expression
    elif i == ')':
        while Stack[-1] != '(':
            Postfix.append(Stack.pop())
        Stack.pop()
    # if i is an operator, then we have to check the priority of the operators
    else:
        Rank = Ranks[i]
        RankStack = Ranks[Stack[-1]]
        # Rules --- A lower priority operator can accept a higher priority operator
        if RankStack < Rank:
            Stack.append(i)
        
        else:
            # If, Rank of Stack[-1] is greater than Rank of i, then Pop the stack and push it into the Postfix expression
            if RankStack > Rank:
                Postfix.append(Stack.pop())
                RankStack = Ranks[Stack[-1]]
                # After deleting the higher priority operator, we have to check with it's next Rank, if it is equal, then again Pop it and push into Postfix
                if RankStack == Rank:
                    Postfix.append(Stack.pop())
                    Stack.append(i)
                else:
                    Stack.append(i)
            else:
                # If Rank of Stack[-1] is equal to Rank of incoming operator, then Pop the stack and push the result into postfix and add i into Stack
                Postfix.append(Stack.pop())
                Stack.append(i)
# Adding the remaining operators from stack into Postfix expression
while len(Stack) != 0:
    Postfix.append(Stack.pop())
print()
print("Given Infix Expression is: ", Infix, "\nPostfix expression is: ", ''.join(Postfix))