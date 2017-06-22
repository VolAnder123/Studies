%������� 6. ����� ������� ���������� ���������� ����
syms an R n 
an = 1 / ((4 ^ (n)) * (2 * n - 1));
R = limit(abs((1/an)^(1/n)),n,inf);
fprintf('������ ���������� �����: %d\n', double(R));
if (R == 0)
    fprintf('�������� ���������� ���� �������� ����\n ������������ ����� x = 0');    
else
    x1 = -sqrt(R) - 5; %����� ����� ������� ����������
    x2 = sqrt(R) - 5; %������ ����� ������� ����������    
    temp = symsum(an * (x1) ^ (2*n - 1), n, 1, inf);
    if (temp == inf) % ��������� ���������� ���� � ����� x1
        open_bracket = '(';
    else
        open_bracket = '[';
    end;
    temp = symsum(an * (x2) ^ (2*n - 1), n, 1, inf);
    if (temp == inf) % ��������� ���������� ���� � ����� x2
        close_bracket = ')';
    else
        close_bracket = ']';
    end;
    fprintf('������� ���������� ���������� ����:  %c%d; %d%c\n', open_bracket, double(x1), double(x2), close_bracket);
end; 
%������� ���������� ���������� ����: (-7; -3)