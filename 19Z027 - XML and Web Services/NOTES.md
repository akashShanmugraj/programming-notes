## Verifying an XML Document with Regular RelaxNG

(use [this](https://www.liquid-technologies.com/online-relaxng-validator) online editor or java based `jing` validator from `brew install jing-trang` )

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

## Verifying an XML Document with Compact RelaxNG

```rnc
element root {
    element class {
        element name {
            text
        },
        element students {
            element student {
                attribute name { text },
                attribute rollnum { text },
                attribute init { text }
            }*
        },
        element strength {
            text
        }?
    }
}
```

Notice that the `?` and `*` have regular meanings here (_zero or one occurrence_ and _zero or more occurrences_)

`<choice>` is the equivalent of `|` and `<group>` is the equivalent of `*`. For example, consider the below regular RNG

```xml
<element name="instant">
    <choice>
        <group>
            <element name="date"> <text/></element>
            <element name ="time"> <text/> </element>
        </group>
        <element name="date-time"> <text/> </element>
    </choice>
</element>
```

instructs the validator that there should either be one element `date-time` or two elements `date` and `time`

similarly a rnc file for the same would look like

```
element instant {
    (
        element date {text},
        element time {text}
        |
        element date-time {text}
    )
}
```

---

## Definition in XML

```xml
<define name="date">
    <element name="date">
        <element name="year"><text/></element>
        <element name="month"><text/></element>
        <element name="day"><text/></element>
    </element>
</define>
```

```
date=element date {
    element year {text},
    element month {text},
    element day {text}
}
```

## Grammar in RNG

```xml
<grammar xmlns="http://relaxng.org/ns/structure/1.0">
    <start>
        <ref name="date"/>
    </start>
    <define name="date">
        <element name="date">
            <element name="year"><text/></element>
            <element name="month"><text/></element>
            <element name="day"><text/></element>
            </element>
    </define>
</grammar>
```

## Datatypes in XML (RNG)

Datatypes can be included by including a datatype library. Can't fool around with the URL, should be a valid datatype library
The following RNG file(s) forces the element year to have a value between 2002 and 2005

```xml
<element name="year" xmlns="http://relaxng.org/ns/structure/1.0" datatypeLibrary="http://www.w3.org/2001/XMLSchema-datatypes">
    <data type="gYear">
        <param name="minInclusive">2002</param>
        <param name="maxInclusive">2005</param>
    </data>
</element>
```

```
element year { 
    xsd:gYear {minInclusive="2002" maxInclusive="2005"} 
}
```

## Interleave in XML
When you want multiple elements to appear in any order.

```xml
<element name="name" xmlns="http://relaxng.org/ns/structure/1.0"> 
    <interleave> 
        <element name="family"><text/></element> 
        <oneOrMore> 
            <element name="given"><text/></element> 
        </oneOrMore> 
    </interleave> 
</element>
```

```rnc
element name { 
    element family {text} 
    & 
    element given {text}+ 
}
```