% ������� 3. ������������ ���� �� ����������. ������� �`��������
syms n an dalamber_limit 
an = (n / gamma(2 * n + 1)) * tan(1/(5 ^ n));
dalamber_limit = limit(abs(subs(an, n, n + 1) / an), n, inf);
disp('������ �� �''��������:');
disp(dalamber_limit);
dalamber_limit = double(dalamber_limit);
if (dalamber_limit < 1)
    disp('��� ��������!');
elseif (dalamber_limit > 1)
    disp('��� ����������!');
else
    disp('����� �������������� ������������');
end;
%������ �� �''��������:
%0
%��� ��������!