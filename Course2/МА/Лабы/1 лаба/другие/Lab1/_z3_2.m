% 3.2 ������������ ���� �� ���������� ��� ������ �������� ����
syms n a f
f = (n/(3*n+1))^(2*n+1);
a = limit(f, n, inf);
disp('������ �������� ������������������:');
disp(a)
if (a == 0)
    syms f_lim
    f_lim = limit(f^(1./n), n, inf);
    disp('������ �� ����:');
disp(f_lim);
    f_lim = double(f_lim);
    if (f_lim < 1)
        disp('��� ��������!');
    else
        if (f_lim> 1)
disp('��� ����������!');
else
disp('����� �������������� ������������');
end;
    end;
else
     disp('��� ����������!');
end;