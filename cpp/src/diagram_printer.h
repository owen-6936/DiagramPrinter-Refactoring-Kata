
#ifndef DIAGRAM_PRINTER_H
#define DIAGRAM_PRINTER_H

#include <string>
#include "flowchart_diagram.h"
#include "diagram_summary.h"
#include "pages_builder.h"
#include "printable_diagram.h"


class DiagramPrinter {
public:
    static const std::string Spreadsheet;
    static const std::string Pdf;

    DiagramPrinter() {};

    bool PrintSummary(FlowchartDiagram* diagram, const std::string& language, std::string& summaryText);
    
    bool PrintDiagram(FlowchartDiagram* diagram,
                      const std::string &folder = "",
                      const std::string &filename = "");
    
    bool PrintReport(FlowchartDiagram* diagram, 
                    const std::string& reportTemplate,
                    const std::string& folder = "",
                    const std::string& filename = "",
                    bool summarize = true);

    bool PrintPages(FlowchartDiagram* diagram, PagesBuilder& builder);

    bool ValidateReport(const std::string& template_str, const FlowchartReportItems *substitutions);
    std::string CreateReport(const std::string& template_str, const std::vector<std::string> *substitutions);

private:
    std::string GetTargetFilename(const std::string& folder, const std::string& filename);
    
};

#endif // DIAGRAM_PRINTER_H
