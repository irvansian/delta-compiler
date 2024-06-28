Syntax:

<program> ::= {<statement>}
<statement> ::= <identifier> "=" <expression>
<expression> ::= <term> {("+" | "-") <term>}
<term> ::= <factor> {("*" | "/") <factor>}
<factor> ::= <number> | <identifier> | "(" <expression> ")"
<number> ::= <digit> {<digit>}
<identifier> ::= <letter> {<letter> | <digit> | "_"}
