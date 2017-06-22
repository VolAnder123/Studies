%������� 1. ������� �������
%y' + sin(x-y) = sin(x+y)
syms x y Ur Title x_new y_new DU Message;
Ur = 'sin(x+y) - sin(x-y)';
DU = ['Dy = ', char(Ur)]; % ������������ �������. ���������
y = dsolve(DU, 'x'); % ������� ����������������� ���������
y = y(2);
fprintf('y = ');
pretty(simplify(y)); % ������ ������� ���������
y_derivative = diff(y);
pretty(simplify(y_derivative));
grid on; hold on; % �������� ������������ �����
xlabel('��� Y'); % ����������� ��� OX
ylabel('��� Y'''); % ����������� ��� OY
Message = ['y=', char(y)]; % ������� ��� ������� �������
x_new = -10:0.1:10; % ��������� ����� �������� ����������
y = subs(y, x, x_new); % ����������� ��������� 
y_derivative = subs(y_derivative, x, x_new); % ����������� ���������
for cycle = -4 : 1: 4
    y_new = subs(y, cycle); % ����������� ���������  
    y_new_derivative = subs(y_derivative, cycle);
    plot(y_new, y_new_derivative);
end;

legend(char(Message)); % ������� �������
%�����: y = 2*atan(exp(C5 + 2*sin(x)))