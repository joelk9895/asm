import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JFrame implements ActionListener {
    // Components
    private JTextField textField;
    private JButton[] numberButtons;
    private JButton[] functionButtons;
    private JButton addButton, subButton, mulButton, divButton, eqButton, clrButton, delButton;
    private JPanel panel;

    // Variables
    private double num1, num2, result;
    private char operator;

    // Constructor
    public Calculator() {
        // Frame setup
        setTitle("Calculator");
        setSize(400, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        // Textfield
        textField = new JTextField();
        textField.setBounds(50, 25, 300, 50);
        textField.setFont(new Font("Arial", Font.PLAIN, 24));
        textField.setEditable(false);

        // Number buttons
        numberButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].setFont(new Font("Arial", Font.PLAIN, 20));
            numberButtons[i].addActionListener(this);
        }

        // Function buttons
        functionButtons = new JButton[7];
        addButton = new JButton("+");
        subButton = new JButton("-");
        mulButton = new JButton("*");
        divButton = new JButton("/");
        eqButton = new JButton("=");
        clrButton = new JButton("C");
        delButton = new JButton("DEL");

        functionButtons[0] = addButton;
        functionButtons[1] = subButton;
        functionButtons[2] = mulButton;
        functionButtons[3] = divButton;
        functionButtons[4] = eqButton;
        functionButtons[5] = clrButton;
        functionButtons[6] = delButton;

        for (int i = 0; i < 7; i++) {
            functionButtons[i].setFont(new Font("Arial", Font.PLAIN, 20));
            functionButtons[i].addActionListener(this);
        }

        // Panel
        panel = new JPanel();
        panel.setBounds(50, 100, 300, 400);
        panel.setLayout(new GridLayout(4, 4, 10, 10));

        // Adding components to panel
        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(addButton);
        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(subButton);
        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(mulButton);
        panel.add(clrButton);
        panel.add(numberButtons[0]);
        panel.add(eqButton);
        panel.add(divButton);

        // Adding components to frame
        add(textField);
        add(panel);

        // Frame visibility
        setLayout(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new Calculator();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 10; i++) {
            if (e.getSource() == numberButtons[i]) {
                textField.setText(textField.getText() + i);
            }
        }

        if (e.getSource() == addButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '+';
            textField.setText("");
        }

        if (e.getSource() == subButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '-';
            textField.setText("");
        }

        if (e.getSource() == mulButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '*';
            textField.setText("");
        }

        if (e.getSource() == divButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '/';
            textField.setText("");
        }

        if (e.getSource() == eqButton) {
            num2 = Double.parseDouble(textField.getText());

            switch (operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                        textField.setText("Error");
                        return;
                    }
                    break;
            }

            textField.setText(String.valueOf(result));
            num1 = result;
        }

        if (e.getSource() == clrButton) {
            textField.setText("");
            num1 = num2 = result = 0;
        }

        if (e.getSource() == delButton) {
            String currentText = textField.getText();
            if (currentText.length() > 0) {
                textField.setText(currentText.substring(0, currentText.length() - 1));
            }
        }
    }
}
