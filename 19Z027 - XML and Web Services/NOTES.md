## Verifying an XML Document with RelaxNG 
(use [this](https://www.liquid-technologies.com/online-relaxng-validator) online editor)

```xml
<root>
  <class>
    <name>BE CSE G1 2026</name>
    <students>
      <student name="akash" rollnum="255" init="s"/>
      <student name="raghav" rollnum="261" init="r"/>
    </students>
  </class>
</root>
```

```xml
<element name="root" xmlns="http://relaxng.org/ns/structure/1.0">
  <element name="class">
    <element name="name">
      <text/>
    </element>
    <element name="students">
      <zeroOrMore>
        <element name="student">
          <attribute name="name"/>
          <attribute name="rollnum"/>
          <attribute name="init"/>
        </element>
      </zeroOrMore>
    </element>
  </element>
</element>
```

Note: 
- `<list>` and `<sequence>` tags are not supported
- Unable to validate presence of a INT value
