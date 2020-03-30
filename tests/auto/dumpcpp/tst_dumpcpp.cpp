/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtTest/QtTest>
#include "ieframe.h" // generated header
#include <QApplication>

class tst_dumpcpp : public QObject
{
    Q_OBJECT

private slots:
    void toggleAddressBar();
};

// A simple test to verify that an object can be instantiated and interacted with
void tst_dumpcpp::toggleAddressBar()
{
    QSKIP("Crashes in Qt 6 pending rewrite of dumpcpp for new QMetaObject", Abort); // Qt 6 Fixme
    SHDocVw::WebBrowser* webBrowser = new SHDocVw::WebBrowser;
    QVERIFY(webBrowser);
    bool addressBar = webBrowser->AddressBar();
    addressBar = !addressBar;
    webBrowser->SetAddressBar(addressBar);
    QVERIFY(webBrowser->AddressBar() == addressBar);
    delete webBrowser;
}

QTEST_MAIN(tst_dumpcpp)
#include "tst_dumpcpp.moc"
