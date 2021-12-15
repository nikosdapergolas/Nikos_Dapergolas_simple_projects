%------------------------
Ts = 0.002;
Nmax = t_max / Ts;
n1 = -Nmax:1:Nmax;
% Το διανυσμα αυτο αποθηκευει τις ακαιρεες τιμες δειγματοληψιας
xs = cos(100*pi*n1*Ts) + cos(200*pi*n1*Ts) + sin(500*pi*n1*Ts);
% το διανυσμα αυτο χρησιμοποιειται για την αποθηκευση τιμων του
% ανακατασκευασμενου σηματος
x1 = zeros(1,length(t));
% αποθηκευει την ανακατασκευασμενη εκδοχη του αρχικου σηματος για περιοδο
% δειγματοληψιας 0.002 sec 
for k = 1:1:length(t)
    x1(k) = xs * sinc((t(k)-n1*Ts)/Ts)';
end

figure('Name','Reconstructed Signal for Ts = 0.002');
hold on
plot(t,x,'-r','LineWidth',1.7);
plot(t,x1,'*b','LineWidth',1.1);
xlabel('Time');
ylabel('x(t) and x1(t)');
grid on