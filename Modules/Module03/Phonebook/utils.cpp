#include "Utils.h"

bool containsNonAlphabetic(const QString& text) {
    for (int i = 0; i < text.length(); ++i) {
        QChar c = text[i];
        if (!(c.isLetter() || c == ' ')) {
            return true;
        }
    }
    return false;
}


bool containsOnlyDigits(const QString& text) {
    for (int i = 0; i < text.length(); ++i) {
        if (!text[i].isDigit()) {
            return false;
        }
    }
    return true;
}


bool isValidEmail(const QString &email) {
    QRegularExpression emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    QRegularExpressionMatch match = emailPattern.match(email);

    return match.hasMatch();
}
