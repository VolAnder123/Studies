% ������� 3. ������������ ���� �� ���������� ��� ������ �������� �`��������
syms n l f
f = ((2*n + 3) / (n + 1))^n*n; 
l = limit(f, n, inf);
disp('������ �������� ������������������:');
disp(l)
if (l == 0)
    syms f_lim
    f_lim = limit(subs(f, n, n+1) / f, n, inf);
    disp('������ �� �''��������:');
    disp(f_lim);
    f_lim = double(f_lim);
    if (f_lim < 1)
        disp('��� ��������!');
    elseif (f_lim > 1)
        disp('��� ����������!');
    else
        disp('����� �������������� ������������');
    end;
else
     disp('��� ����������!');
end;
