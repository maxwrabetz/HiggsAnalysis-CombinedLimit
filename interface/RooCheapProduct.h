#ifndef HiggsAnalysis_CombinedLimit_RooCheapProduct_h
#define HiggsAnalysis_CombinedLimit_RooCheapProduct_h
#include <RooAbsReal.h>
#include <RooListProxy.h>
#include <vector>

class RooCheapProduct : public RooAbsReal {
    public:
        RooCheapProduct() {}
        RooCheapProduct(const char *name, const char *title, const RooArgList &terms, bool pruneConstants=false);
        RooCheapProduct(const RooCheapProduct& other, const char* name=0);
        ~RooCheapProduct() override {}
        TObject *clone(const char *newname) const override { return new RooCheapProduct(*this,newname); } 
        const RooArgList & components() const { return terms_; }
    protected:
        RooListProxy terms_;
        std::vector<RooAbsReal *> vterms_; //! not to be serialized
        double offset_;
        Double_t evaluate() const override ;
    private:
        ClassDefOverride(RooCheapProduct,1)
};

#endif
