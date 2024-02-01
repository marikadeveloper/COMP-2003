# C programming review

## Variables

### Best practices

- do not put initialized and non-initialized variables on the same line
- initialization creates storage location, be careful of how much memory you're using
- unsigned creation means only positive int
- most common system configs give 16/32 bits for int and 32 bits for long

### Chars

- char is used for storing characters (letters, punctuation)
  - but technically this is numbers (ie. ASCII)
  - look at the code below
  - the character typed is stored as type "c"
  - can be displayed as a decimal value (ASCII)
