syms n l f
f = (cos(n)) / n*n;
l = limit(f, n, inf);
disp('������ �������� ������������������ (������� ��������):');
disp(l)
if (l == 0)
disp('��� ��������!');
syms f_lim
f_lim = limit(f / (1 / n*n), n, inf);
disp('������ ��������� � ������������� �����:');
disp(f_lim);
f_lim = double(f_lim);
if (f_lim == 0)||(f_lim == +inf)|| (f_lim == -inf)
disp('�������� ��� �������� ���������!');
else
disp('�������� ��� �������� �������!');
end;
else
disp('��� ��������!');
end;