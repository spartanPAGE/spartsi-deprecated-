#spartsi - TreeStructInfo 2.0 api for C++ >= 14

##Looking for something interesting?
Check out some integration tests!
https://github.com/spartanPAGE/spartsi/tree/master/spartsi/test/parser/impl/integration


## Example parser usage
```C++
std::string source = SPARTSI_STRF('#',
    treestructinfo "2.0"    #
      attr normal "1"       #

      node normal           #
        attr normal "2"     #
        ref attr ref        #
      end node              #

      ref node ref          #
    end tree                #

    ref attr ref "3"        #

    ref node ref            #
      ref attr ref          #
    end ref node            #

    ref attr ref "4"        #
);

//done
auto tree = spartsi::parse(source);
```

## Example builder usage
```C++
auto to_be_linked = build()
    ("real comment")
    .treestructinfo("2.0").name("to be linked")
        .attr("attr from linked tree", "bazinga")
    .end_tree().get();

auto first_tree = build()
    .treestructinfo("2.0").name("first")
        ("comment of the first tree linkage")
        .tree("linked", to_be_linked)
    .end_tree().get();

auto second_tree = build()
    .treestructinfo("2.0").name("second")
        ("comment of the second tree linkage")
        .tree("linked", to_be_linked)
    .end_tree().get();
```