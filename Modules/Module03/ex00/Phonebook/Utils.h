#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QRegularExpression>

bool containsNonAlphabetic(const QString& text);
bool containsOnlyDigits(const QString& text);
bool isValidEmail(const QString &email);

#endif // UTILS_H
