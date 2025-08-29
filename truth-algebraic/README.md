Truth-Table Helper for Digital Logic (C++)

A tiny C++ program that evaluates the Boolean expression

𝑓(𝑤,𝑥,𝑦,𝑧)  = (𝑤 ∧ 𝑥)′∧ (𝑦′∨ 𝑧′)′  =  NAND(𝑤, 𝑥) ∧ (𝑦 ∧ 𝑧)

This started as a homework helper for truth tables in a Digital Logic course. It reads four binary inputs (w x y z) and prints the resulting value of f.

What the code does

Inputs: four bits w x y z entered as characters '0' or '1'.

Intermediate results:

wAndx(w,x,wx) computes NAND: (𝑤 ∧ 𝑥)′  -> returns '0'/'1' in wx.

yAndz(y,z,yz) computes (𝑦′ ∨ 𝑧′)′ -> y∧z. Returns '0'/'1' in yz.
By De Morgan, this equals 𝑦 ∧ 𝑧

Output: vValue = '1' iff wx == '1' and yz == '1'.
That is 𝑓 = NAND(𝑤,𝑥) ∧ (𝑦 ∧ 𝑧)

Note on types: The program uses char for bits ('0' and '1'). Be careful to compare against character literals ('0', '1') rather than integers (0, 1) to avoid printing null chars.
