QtP
---

Qt properties is a wonderful concept. Linking a property from one object to a property in another is a flexible and intuitive way to interconnect separate entities in an application. 

However, two things bother me, escpecially when dissecting code I haven't written myself:
- linking properties to one another requires two operations: establishing a signal-slot connection, and an initial assignment. When omitting the latter, consistency isn't guaranteed. (It may be because of how and when signals are triggered when the application initializes, but this it isn't apparent to the reader, or worse, to someone who has to make changes to the code)
- properties aren't always mapped one-on-one. Often, a property in one object results from an operation (function) on one, two or more properties. Nevertheless, this operation is often so basic, that the required separate function code block for this is harder to interpret than if that code could be inlined. Especially when many such property links are made with simple operations, a lot of code clutter in both slot declarations and definitions occurs. 

Introducing "QtP". From now on, given
  QSpinBox * sp(new QSpinBox);
  QLCDNumber * lcd(new QLCDNumber);

you don't need to
  connect(sp, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
  lcd->display(sp->value());

but instead
  QtP(lcd) << QtP(sp);

Quite short and clear, right?

Well, to be completely honest, this works, but because QtP automatically associates QSpinBox and QLCDNumber with (int, "value"). When writing your own custom classes, or when accessing more than just the 'primary' property of an object, you would have done:
  QtPInt(lcd, "value") << QtPInt(sp, "value);

which, in my opinion, is still very short and readable.

To make things more interesting, you can perform functions:
  QtP(lcd) << 2 * QtP(sp) + 5;

but for more of that, I refer you to the example code in Test.cpp.

Enjoy!
And your feedback is much appreciated!

